#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int DN[2] = { 0, 1 };
const int DM[2] = { 1, 0 };

int N, M;
int I[51], C[51][51];

void Turn()
{
	int X, D, K;
	cin >> X >> D >> K;
	D = (D == 0 ? -1 : 1);
	for (int i = 1; i * X <= N; ++i)
	{
		I[i * X] = (I[i * X] + D * K) % M;
	}
}

bool IsNumExist()
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (C[i][j])
			{
				return true;
			}
		}
	}

	return false;
}

bool IsValid(int NN, int NM)
{
	return (NN <= N);
}

bool NoNeighbor()
{
	bool bFound = false;

	queue<p> EQ;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			int CM = j + I[i];
			CM = (CM < 1 ? M + CM : (CM > M ? CM - M : CM));
			if (C[i][CM] == 0)
			{
				continue;
			}

			bool bCFound = false;
			for (int k = 0; k < 2; ++k)
			{
				int NN = i + DN[k];
				int NM = CM + DM[k];
				NM = (NM < 1 ? M + NM : (NM > M ? NM - M : NM));
				if (IsValid(NN, NM))
				{
					if (NN != i)
					{
						NM = j + I[NN];
						NM = (NM < 1 ? M + NM : (NM > M ? NM - M : NM));
					}

					if (C[i][CM] == C[NN][NM])
					{
						bCFound = true;
						EQ.emplace(NN, NM);
					}
				}
			}

			if (bCFound)
			{
				bFound = true;
				EQ.emplace(i, CM);
			}
		}
	}

	while (!EQ.empty())
	{
		int NN = EQ.front().first;
		int NM = EQ.front().second;
		EQ.pop();

		C[NN][NM] = 0;
	}

	return (!bFound);
}

int GetSum()
{
	int Sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			Sum += C[i][j];
		}
	}

	return Sum;
}

int NumCount()
{
	int Cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (C[i][j])
			{
				++Cnt;
			}
		}
	}

	return Cnt;
}

float GetAverage()
{
	return float(GetSum()) / NumCount();
}

void ManipulateNum(float Average)
{
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (C[i][j] == 0)
			{
				continue;
			}

			if (C[i][j] > Average)
			{
				--C[i][j];
			}
			else if (C[i][j] < Average)
			{
				++C[i][j];
			}
		}
	}
}

void Test()
{
	Turn();
	if (IsNumExist() && NoNeighbor())
	{
		ManipulateNum(GetAverage());
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> N >> M >> T;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			cin >> C[i][j];
		}
	}

	for (int i = 0; i < T; ++i)
	{
		Test();
	}

	cout << GetSum();
}