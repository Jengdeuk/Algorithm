#include <iostream>
using namespace std;

typedef pair<int, int> p;

int N, S[50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	if (N == 1)
	{
		cout << 'A';
		return 0;
	}
	else if (N == 2)
	{
		if (S[0] == S[1])
		{
			cout << S[0];
		}
		else
		{
			cout << 'A';
		}
		return 0;
	}

	int a = 0;
	if (S[1] - S[0] != 0)
	{
		a = (S[2] - S[1]) / (S[1] - S[0]);
	}

	int b = S[1] - S[0] * a;

	for (int i = 1; i < N; ++i)
	{
		if (S[i] != S[i - 1] * a + b)
		{
			cout << 'B';
			return 0;
		}
	}

	cout << S[N - 1] * a + b;
}