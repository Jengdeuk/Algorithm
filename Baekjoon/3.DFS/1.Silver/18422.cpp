#include <iostream>
#include <string>
using namespace std;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
char Map[100][100];
bool Vst[100][100];

void DFS(int R, int C)
{
	Vst[R][C] = true;

	for (int i = 0; i < 4; ++i)
	{
		int NR = R + DY[i];
		int NC = C + DX[i];
		if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1
			|| Map[NR][NC] == '.' || Vst[NR][NC])
		{
			continue;
		}

		DFS(NR, NC);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		for (int j = 0; j < M; ++j)
		{
			Map[i][j] = S[j];
		}
	}

	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] == '*' && !Vst[i][j])
			{
				++Cnt;
				DFS(i, j);
			}
		}
	}

	cout << Cnt;
}