#include <iostream>
using namespace std;

char C;
char S[2000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> S[i];
	}

	cin >> C;

	int Cnt = 0;
	char Cur = S[1];
	for (int i = 2; i < N - 2; i += 2)
	{
		bool L = (Cur == 'T');
		bool R = (S[i + 1] == 'T');

		if (S[i] == '&')
		{
			Cur = (L && R ? 'T' : 'F');
		}
		else
		{
			Cur = (L || R ? 'T' : 'F');
		}
	}

	if (N == 1)
	{
		if (Cur == C)
		{
			cout << 0;
		}
		else
		{
			cout << 1;
		}

		return 0;
	}

	if (S[N - 1] == '&' && C == 'T')
	{
		if (Cur == 'F' && S[N] == 'F')
		{
			cout << 2;
		}
		else if (Cur == 'F' || S[N] == 'F')
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else if (S[N - 1] == '|' && C == 'T')
	{
		if (Cur == 'T' || S[N] == 'T')
		{
			cout << 0;
		}
		else
		{
			cout << 1;
		}
	}
	else if (S[N - 1] == '&' && C == 'F')
	{
		if (Cur == 'T' && S[N] == 'T')
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
	else
	{
		if (Cur == 'T' && S[N] == 'T')
		{
			cout << 2;
		}
		else if (Cur == 'T' || S[N] == 'T')
		{
			cout << 1;
		}
		else
		{
			cout << 0;
		}
	}
}