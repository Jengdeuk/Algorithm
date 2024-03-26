#include <iostream>
#include <string>
#include <queue>
using namespace std;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
bool Wall[1000][1000];
bool Visited[1000][1000];

int Area[1000][1000];
int AreaSize[1000000];

int BFS(int AreaNum, int SRow, int SCol)
{
	queue<pair<int, int>> SQ;
	SQ.emplace(SRow, SCol);
	Visited[SRow][SCol] = true;
	Area[SRow][SCol] = AreaNum;

	int Cnt = 1;
	while (!SQ.empty())
	{
		int R = SQ.front().first;
		int C = SQ.front().second;
		SQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (NR < 0 || NR > N - 1
				|| NC < 0 || NC > M - 1
				|| Wall[NR][NC]
				|| Visited[NR][NC])
			{
				continue;
			}

			Visited[NR][NC] = true;
			Area[NR][NC] = AreaNum;
			SQ.emplace(NR, NC);
			++Cnt;
		}
	}

	return Cnt;
}

int Counting(int Row, int Col)
{
	int Cnt = 1;
	int AreaNum[4] = {};
	for (int i = 0; i < 4; ++i)
	{
		int NR = Row + DY[i];
		int NC = Col + DX[i];
		if (NR < 0 || NR > N - 1
			|| NC < 0 || NC > M - 1
			|| Wall[NR][NC])
		{
			continue;
		}

		bool bSameArea = false;
		int AN = Area[NR][NC];
		for (int j = 0; j < i; ++j)
		{
			if (AN == AreaNum[j])
			{
				bSameArea = true;
			}
		}

		if (!bSameArea)
		{
			AreaNum[i] = AN;
			Cnt += AreaSize[AN];
		}
	}

	return Cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string Str;
		cin >> Str;

		for (int j = 0; j < M; ++j)
		{
			int Num = Str[j] - '0';
			Wall[i][j] = Num;
		}
	}

	int AreaNum = 1;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!Wall[i][j] && !Visited[i][j])
			{
				AreaSize[AreaNum] = BFS(AreaNum, i, j);
				++AreaNum;
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int Cnt = (Wall[i][j]) ? Counting(i, j) : 0;
			cout << Cnt % 10;
		}
		cout << '\n';
	}
}