#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A = 0;
	for (int i = 0; i < 3; ++i)
	{
		string S;
		cin >> S;

		if (S[0] != 'F' && S[0] != 'B')
		{
			int N = stoi(S);
			A = N + (3 - i);
		}
	}

	if (A % 3 == 0 && A % 5 == 0)
	{
		cout << "FizzBuzz";
	}
	else if (A % 3 == 0)
	{
		cout << "Fizz";
	}
	else if (A % 5 == 0)
	{
		cout << "Buzz";
	}
	else
	{
		cout << A;
	}
}