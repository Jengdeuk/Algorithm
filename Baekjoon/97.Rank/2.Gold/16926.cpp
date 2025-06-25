#include <iostream>
#include <cstring>
using namespace std;

const int DX[4] = { 0, 1, 0, -1 };
const int DY[4] = { 1, 0, -1, 0 };

int N, M, S[300][300];
bool V[300][300];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M && V[R][C] == false);
}

void Rotate()
{
	memset(V, false, sizeof(V));

	int SR = 0, SC = 0;
	while (V[SR][SC] == false)
	{
		int R = SR, C = SC, D = 0;
		V[R][C] = true;

		int Pre = S[R][C];
		while (true)
		{
			int NR = R + DY[D];
			int NC = C + DX[D];
			if (NR == SR && NC == SC)
			{
				S[NR][NC] = Pre;
				break;
			}
			else if (IsValid(NR, NC))
			{
				int Temp = S[NR][NC];
				S[NR][NC] = Pre;
				Pre = Temp;
				R = NR;
				C = NC;
				V[R][C] = true;
			}
			else
			{
				D = (D + 1 > 3 ? 0 : D + 1);
			}
		}

		SR++;
		SC++;
	}
}

void Print()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << S[i][j] << ' ';
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	
	int R;
	cin >> R;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> S[i][j];
		}
	}

	while (R--)
	{
		Rotate();
	}

	Print();
}