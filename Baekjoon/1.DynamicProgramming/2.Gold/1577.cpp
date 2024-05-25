#include <iostream>
#include <list>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

int N, M, K;
list<p> Wall[101][101];
ll DP[101][101];

bool DontGo(int R, int C, int NR, int NC)
{
	if (!Wall[R][C].empty())
	{
		for (const p& Ngb : Wall[R][C])
		{
			if (Ngb.first == NR && Ngb.second == NC)
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
	{
		int A, B, C, D;
		cin >> A >> B >> C >> D;
		Wall[A][B].emplace_back(C, D);
		Wall[C][D].emplace_back(A, B);
	}

	DP[0][0] = 1;

	for (int j = 1; j <= M; ++j)
	{
		if (DontGo(0, j, 0, j - 1))
		{
			break;
		}

		DP[0][j] = 1;
	}

	for (int i = 1; i <= N; ++i)
	{
		if (DontGo(i, 0, i - 1, 0))
		{
			break;
		}

		DP[i][0] = 1;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			if (!DontGo(i, j, i, j - 1))
			{
				DP[i][j] += DP[i][j - 1];
			}

			if (!DontGo(i, j, i - 1, j))
			{
				DP[i][j] += DP[i - 1][j];
			}
		}
	}

	cout << DP[N][M];
}