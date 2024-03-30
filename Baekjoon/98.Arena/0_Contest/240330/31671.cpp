#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int DX[2] = { 1, 1 };
const int DY[2] = { 1, -1 };

int N, M;
bool DontGo[1001][2001];
p Predecessor[1001][2001];

bool BFS()
{
	bool bArrived = false;

	queue<p> SQ;
	DontGo[0][0] = true;
	SQ.emplace(0, 0);
	while (!SQ.empty())
	{
		int R = SQ.front().first;
		int C = SQ.front().second;
		SQ.pop();
		if (R == 0 && C == 2 * N)
		{
			bArrived = true;
		}

		for (int i = 0; i < 2; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (NR < 0 || NR > N
				|| NC > 2 * N
				|| (NC <= N && NR > NC)
				|| (NC > N && NR > N - (NC - N))
				|| (NR + NC) % 2 == 1
				|| DontGo[NR][NC])
			{
				continue;
			}

			DontGo[NR][NC] = true;
			Predecessor[NR][NC] = p(R, C);
			SQ.emplace(NR, NC);
		}
	}

	return bArrived;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int X, Y;
		cin >> X >> Y;
		DontGo[Y][X] = true;
	}

	if (BFS())
	{
		int R = Predecessor[0][2 * N].first;
		int C = Predecessor[0][2 * N].second;
		int MaxY = max(MaxY, R);
		while (R != 0 || C != 0)
		{
			int NR = Predecessor[R][C].first;
			int NC = Predecessor[R][C].second;
			MaxY = max(MaxY, NR);
			R = NR;
			C = NC;
		}

		cout << MaxY;
	}
	else
	{
		cout << -1;
	}
}