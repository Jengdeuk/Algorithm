#include <iostream>
#include <string>
using namespace std;

int N;
string S;
int A[26];

bool IsValid()
{
	int Count = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (A[i] % 2 == 1)
		{
			++Count;
		}
	}

	if ((N % 2 == 0 && Count > 0) || (N % 2 == 1 && Count != 1))
	{
		return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> S;
	N = S.size();
	for (int i = 0; i < N; ++i)
	{
		++A[S[i] - 'A'];
	}

	if (!IsValid())
	{
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	string Answer;
	for (int i = 0; i < 26; ++i)
	{
		while (A[i] >= 2)
		{
			Answer.push_back('A' + i);
			A[i] -= 2;
		}
	}

	for (int i = 0; i < 26; ++i)
	{
		if (A[i] > 0)
		{
			Answer.push_back('A' + i);
			break;
		}
	}

	for (int i = N / 2 - 1; i >= 0; --i)
	{
		Answer.push_back(Answer[i]);
	}

	cout << Answer;
}