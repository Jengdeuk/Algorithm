#include <iostream>
#include <string>
using namespace std;

int N;
string S;

bool IsA(int SI)
{
	for (int i = SI; i < SI + 4; ++i)
	{
		if (i >= N || S[i] != 'X')
		{
			return false;
		}
	}
	
	return true;
}

bool IsB(int SI)
{
	for (int i = SI; i < SI + 2; ++i)
	{
		if (i >= N || S[i] != 'X')
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> S;
	N = S.size();

	string Answer;
	for (int i = 0; i < N; ++i)
	{
		if (S[i] == '.')
		{
			Answer.push_back('.');
		}
		else if (IsA(i))
		{
			i += 3;
			Answer.append("AAAA");
		}
		else if (IsB(i))
		{
			i += 1;
			Answer.append("BB");
		}
		else
		{
			cout << -1;
			return 0;
		}
	}

	cout << Answer;
}