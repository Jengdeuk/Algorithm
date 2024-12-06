#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, p> pp;

const int HDX[8] = { -2, -1, 1, 2, 2, 1, -1, -2 };
const int HDY[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

const int MDX[4] = { -1, 0, 1, 0 };
const int MDY[4] = { 0, -1, 0, 1 };

int K, N, M;
bool Wall[200][200], Vst[31][200][200];

bool IsValid(int Jump, int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M && !Wall[R][C] && !Vst[Jump][R][C]);
}

int BFS()
{
	queue<pp> Q;
	Vst[0][0][0] = true;
	Q.emplace(p(0, 0), p(0, 0));
	while (!Q.empty())
	{
		int Step = Q.front().first.first;
		int Jump = Q.front().first.second;
		int R = Q.front().second.first;
		int C = Q.front().second.second;
		Q.pop();

		if (R == N - 1 && C == M - 1)
		{
			return Step;
		}

		if (Jump < K)
		{
			for (int i = 0; i < 8; ++i)
			{
				int NR = R + HDY[i];
				int NC = C + HDX[i];
				if (IsValid(Jump + 1, NR, NC))
				{
					Vst[Jump + 1][NR][NC] = true;
					Q.emplace(p(Step + 1, Jump + 1), p(NR, NC));
				}
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + MDY[i];
			int NC = C + MDX[i];
			if (IsValid(Jump, NR, NC))
			{
				Vst[Jump][NR][NC] = true;
				Q.emplace(p(Step + 1, Jump), p(NR, NC));
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> K >> M >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Wall[i][j];
		}
	}

	cout << BFS();
}