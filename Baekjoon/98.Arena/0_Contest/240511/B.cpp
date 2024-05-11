#include <iostream>
#include <string>
using namespace std;

string S;

bool Check1()
{
	int Small = 0, Big = 0;
	for (int i = 0; i < S.size(); ++i)
	{
		if (S[i] >= 'a' && S[i] <= 'z')
		{
			++Small;
		}
		else if (S[i] >= 'A' && S[i] <= 'Z')
		{
			++Big;
		}
	}

	return (Big <= Small);
}

bool Check2()
{
	return (S.size() <= 10);
}

bool Check3()
{
	for (int i = 0; i < S.size(); ++i)
	{
		if (S[i] < '0' || S[i] > '9')
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> S;

		if (Check1() && Check2() && Check3())
		{
			cout << S;
			exit(0);
		}
	}
}