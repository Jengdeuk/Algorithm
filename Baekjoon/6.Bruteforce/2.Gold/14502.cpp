#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> position;

int N, M;
int Map[8][8];

int MaxVirus;
position Virus[10];

const int MaxAdd = 3;
position AddWall[MaxAdd];

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

queue<position> SQ;
bool Visited[8][8];

int Max;

void BFS()
{
	int Solution[8][8];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			Solution[i][j] = Map[i][j];
			Visited[i][j] = false;
		}
	}

	for (int i = 0; i < MaxAdd; ++i)
	{
		Solution[AddWall[i].first][AddWall[i].second] = 1;
	}

	for (int i = 0; i < MaxVirus; ++i)
	{
		SQ.emplace(Virus[i].first, Virus[i].second);
	}

	while (!SQ.empty())
	{
		int Row = SQ.front().first;
		int Col = SQ.front().second;
		SQ.pop();

		if (Visited[Row][Col])
		{
			continue;
		}

		Visited[Row][Col] = true;
		for (int i = 0; i < 4; ++i)
		{
			int NR = Row + DY[i];
			int NC = Col + DX[i];
			if (NR < 0 || NC < 0 || NR > N - 1 || NC > M - 1
				|| Visited[NR][NC] || Solution[NR][NC] == 1)
			{
				continue;
			}

			Solution[NR][NC] = 2;
			SQ.emplace(NR, NC);
		}
	}
	
	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Solution[i][j] == 0)
			{
				++Cnt;
			}
		}
	}

	if (Cnt > Max)
	{
		Max = Cnt;
	}
}

void DFS(int Row, int Col, int Add)
{
	if (Add == MaxAdd)
	{
		BFS();
		return;
	}

	if (Col > M - 1)
	{
		Col %= M;
		++Row;
	}

	if (Row > N - 1)
	{
		return;
	}

	if (Map[Row][Col] != 0)
	{
		DFS(Row, Col + 1, Add);
		return;
	}

	AddWall[Add] = position(Row, Col);
	DFS(Row, Col + 1, Add + 1);
	DFS(Row, Col + 1, Add);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Map[i][j];

			if (Map[i][j] == 2)
			{
				Virus[MaxVirus] = position(i, j);
				++MaxVirus;
			}
		}
	}

	DFS(0, 0, 0);

	cout << Max;
}