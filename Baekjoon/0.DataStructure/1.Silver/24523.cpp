#include <iostream>
using namespace std;

int N, I;
int S[1000000], R[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
		if (i == 0)
		{
			I = 0;
			continue;
		}

		while (I < N && S[i] != S[I])
		{
			R[I++] = i + 1;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		if (R[i] != 0)
		{
			cout << R[i] << ' ';
		}
		else
		{
			cout << -1 << ' ';
		}
	}
}