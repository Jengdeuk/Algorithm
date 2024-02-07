#include <iostream>
#include <string>
using namespace std;

void TestCase()
{
	string Input;
	cin >> Input;

	int Count = 0;
	for (int i = 0; i < Input.length(); ++i)
	{
		if (Input[i] == '(')
		{
			++Count;
		}
		else if (Input[i] == ')')
		{
			--Count;
			if (Count < 0)
			{
				cout << "NO" << '\n';
				return;
			}
		}
	}

	if (Count > 0)
	{
		cout << "NO" << '\n';
	}
	else
	{
		cout << "YES" << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		TestCase();
	}
}