#include <iostream>
#include <string>
using namespace std;

void Test()
{
	int N;
	cin >> N;

	if (N == 1)
	{
		cout << 0 << '\n';
		return;
	}

	string str;
	if (N % 2 == 0)
	{
		for (int i = 0; i < N; ++i)
		{
			str.push_back('1');
		}
	}
	else
	{
		str.push_back('1');
		for (int i = 1; i < N - 1; ++i)
		{
			str.push_back('2');
		}
		str.push_back('1');
	}

	for (int i = 0; i < N; ++i)
	{
		cout << str[i] - '0';
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}