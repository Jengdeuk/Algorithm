#include <iostream>
#include <string>
using namespace std;

void Test()
{
	string Input;
	cin >> Input;

	bool N = false;
	int FindIndex = Input.size();
	for (int i = 0; i < Input.size(); ++i)
	{
		if (Input[i] != '!')
		{
			N = Input[i] - '0';
			FindIndex = i;
			continue;
		}
		
		if (i > FindIndex)
		{
			N = true;
		}
	}

	for (int i = 0; i < FindIndex; ++i)
	{
		N = !N;
	}

	cout << N << '\n';
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