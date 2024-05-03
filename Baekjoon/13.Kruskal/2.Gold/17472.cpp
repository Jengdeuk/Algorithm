#include <iostream>
#include <climits>
#include <list>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> pp;

const int Infinite = INT_MAX;
const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M, A;
int Map[10][10];
bool Visited[10][10];
int Distance[7][7], Root[7];
list<pp> Edge;

void Initialize();
void DFS(int R, int C);
void Trace(int R, int C);
int Kruskal();
int Find(int Node);
void Union(int NodeA, int NodeB);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Initialize();
	cout << Kruskal();
}

void Initialize()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Map[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] && !Visited[i][j])
			{
				++A;
				DFS(i, j);
			}
		}
	}

	for (int i = 1; i <= A; ++i)
	{
		for (int j = 1; j <= A; ++j)
		{
			Distance[i][j] = Infinite;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j])
			{
				Trace(i, j);
			}
		}
	}
}

void DFS(int R, int C)
{
	Visited[R][C] = true;
	Map[R][C] = A;
	for (int i = 0; i < 4; ++i)
	{
		int NR = R + DY[i];
		int NC = C + DX[i];
		if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1 || Visited[NR][NC] || !Map[NR][NC])
		{
			continue;
		}

		DFS(NR, NC);
	}
}

void Trace(int R, int C)
{
	int Area = Map[R][C];
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 1; j < 10; ++j)
		{
			int NR = R + DY[i] * j;
			int NC = C + DX[i] * j;
			if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1
				|| ((j == 1 || j == 2) && Map[NR][NC]) || Map[NR][NC] == Area)
			{
				break;
			}

			if (Map[NR][NC])
			{
				Distance[Area][Map[NR][NC]] = min(Distance[Area][Map[NR][NC]], j - 1);
				break;
			}
		}
	}
}

int Kruskal()
{
	for (int i = 1; i <= A; ++i)
	{
		Root[i] = i;

		for (int j = 1; j <= A; ++j)
		{
			if (Distance[i][j] == Infinite)
			{
				continue;
			}

			Edge.emplace_back(Distance[i][j], p(i, j));
		}
	}

	Edge.sort();

	int Cnt = 0, Weight = 0;
	for (const pp& E : Edge)
	{
		if (Cnt == A - 1)
		{
			break;
		}

		int D = E.first;
		int U = E.second.first;
		int V = E.second.second;
		if (Find(U) == Find(V))
		{
			continue;
		}

		Union(U, V);
		Weight += D;
		++Cnt;
	}

	if (Cnt != A - 1)
	{
		return -1;
	}

	return Weight;
}

int Find(int Node)
{
	if (Node == Root[Node])
	{
		return Node;
	}

	return Root[Node] = Find(Root[Node]);
}

void Union(int NodeA, int NodeB)
{
	int A = Find(NodeA);
	int B = Find(NodeB);
	int Min = min(A, B);
	Root[A] = Min;
	Root[B] = Min;
}