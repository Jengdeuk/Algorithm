#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> v;
typedef vector<v> vv;

int N, M, K, B[40][40];
vv S[100];

int Dir;

vv TurnVec(int R, int C, const vv& InVec)
{
	vv Vec((Dir == 0 || Dir == 2 ? R : C), v((Dir == 0 || Dir == 2 ? C : R), 0));
	switch (Dir)
	{
	case 0:
		Vec = InVec;
		break;
	case 1:
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				Vec[j][R - 1 - i] = InVec[i][j];
			}
		}
		break;
	case 2:
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				Vec[R - 1 - i][C - 1 - j] = InVec[i][j];
			}
		}
		break;
	case 3:
		for (int i = 0; i < R; ++i)
		{
			for (int j = 0; j < C; ++j)
			{
				Vec[C - 1 - j][i] = InVec[i][j];
			}
		}
		break;
	}

	return Vec;
}

bool IsValid(int SR, int SC, int R, int C, const vv& Vec)
{
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (Vec[i][j] && B[SR + i][SC + j])
			{
				return false;
			}
		}
	}

	return true;
}

void Paste(int SR, int SC, int R, int C, const vv& Vec)
{
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			if (Vec[i][j])
			{
				B[SR + i][SC + j] = Vec[i][j];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
	{
		int R, C;
		cin >> R >> C;
		S[i] = vv(R, v(C, 0));
		for (int r = 0; r < R; ++r)
		{
			for (int c = 0; c < C; ++c)
			{
				cin >> S[i][r][c];
			}
		}
	}

	for (int k = 0; k < K; ++k)
	{
		bool bPaste = false;

		Dir = 0;
		while (bPaste == false && Dir < 4)
		{
			vv Vec = TurnVec(S[k].size(), S[k].front().size(), S[k]);
			int R = Vec.size();
			int C = Vec.front().size();
			for (int i = 0; i <= N - R; ++i)
			{
				for (int j = 0; j <= M - C; ++j)
				{
					if (IsValid(i, j, R, C, Vec))
					{
						bPaste = true;
						Paste(i, j, R, C, Vec);
						i = N, j = M;
						break;
					}
				}
			}

			Dir++;
		}
	}

	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			Cnt += B[i][j];
		}
	}

	cout << Cnt;
}