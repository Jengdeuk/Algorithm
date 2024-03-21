#include <iostream>
#include <cstring>
using namespace std;

int K;
int S[49];
int Select[6];

void Backtracking(int Idx, int Si)
{
	if (Idx == 6)
	{
		for (int i = 0; i < 6; ++i)
		{
			cout << Select[i] << ' ';
		}
		cout << '\n';

		return;
	}

	if (Si == K)
	{
		return;
	}

	Select[Idx] = S[Si];
	Backtracking(Idx + 1, Si + 1);
	Backtracking(Idx, Si + 1);
}

void Test()
{
	memset(S, false, sizeof(S));
	for (int i = 0; i < K; ++i)
	{
		cin >> S[i];
	}

	Backtracking(0, 0);
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		cin >> K;
		if (K == 0)
		{
			break;
		}

		Test();
	}
}