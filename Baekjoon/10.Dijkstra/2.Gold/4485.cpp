#include <iostream>
#include <climits>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;

const int Inf = INT_MAX;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, T;
int M[125][125], D[125][125];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < N);
}

int Dijkstra()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			D[i][j] = Inf;
		}
	}

	priority_queue<ip, vector<ip>, greater<ip>> PQ;
	D[0][0] = M[0][0];
	PQ.emplace(D[0][0], p(0, 0));
	while (!PQ.empty())
	{
		int Cst = PQ.top().first;
		int R = PQ.top().second.first;
		int C = PQ.top().second.second;
		PQ.pop();
		if (Cst > D[R][C])
		{
			continue;
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (!IsValid(NR, NC))
			{
				continue;
			}

			int NCst = Cst + M[NR][NC];
			if (NCst < D[NR][NC])
			{
				D[NR][NC] = NCst;
				PQ.emplace(NCst, p(NR, NC));
			}
		}
	}

	return D[N - 1][N - 1];
}

void Test()
{
	++T;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> M[i][j];
		}
	}

	int Answer = Dijkstra();
	cout << "Problem " << T << ": " << Answer << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		cin >> N;
		if (N == 0)
		{
			break;
		}

		Test();
	}
}