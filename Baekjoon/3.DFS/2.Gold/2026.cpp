#include <iostream>
using namespace std;

int N, K, F;

int FN[901];
bool Friend[901][901];
int Sel[62];

bool Check()
{
	for (int i = 0; i < K - 1; ++i)
	{
		for (int j = i + 1; j < K; ++j)
		{
			if (!Friend[Sel[i]][Sel[j]])
			{
				return false;
			}
		}
	}

	return true;
}

void DFS(int Idx, int Num)
{
	if (Idx == K)
	{
		if (Check())
		{
			for (int i = 0; i < K; ++i)
			{
				cout << Sel[i] << '\n';
			}

			exit(0);
		}

		return;
	}

	if (Num > N)
	{
		return;
	}

	if (FN[Num] >= K - 1)
	{
		Sel[Idx] = Num;
		DFS(Idx + 1, Num + 1);
	}

	DFS(Idx, Num + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> K >> N >> F;

	for (int i = 0; i < F; ++i)
	{
		int A, B;
		cin >> A >> B;

		++FN[A];
		Friend[A][B] = true;

		++FN[B];
		Friend[B][A] = true;
	}
	
	DFS(0, 1);

	cout << -1;
}