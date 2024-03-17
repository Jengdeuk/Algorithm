#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> p;
typedef pair<pair<int, int>, int> pp;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N;
int Bowl[20][20];
bool Visited[20][20];

int Time, Ate;
int Size = 2;
int Row, Col;

bool Target(int R, int C, int D, int FR, int FC, int FD)
{
	if (Bowl[R][C] < Size
		&& Bowl[R][C] != 0
		&& D <= FD
		&& ((R < FR) || (R == FR && C < FC)))
	{
		return true;
	}

	return false;
}

pp BFS()
{
	memset(Visited, false, sizeof(Visited));

	int FR = N;
	int FC = N;
	int FD = 1000;

	queue<pp> SQ;
	Visited[Row][Col] = true;
	SQ.emplace(p(Row, Col), 0);
	while (!SQ.empty())
	{
		int R = SQ.front().first.first;
		int C = SQ.front().first.second;
		int D = SQ.front().second;
		SQ.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (NR < 0 || NR > N - 1 || NC < 0 || NC > N - 1
				|| Visited[NR][NC] || Bowl[NR][NC] > Size)
			{
				continue;
			}

			Visited[NR][NC] = true;
			if (Target(NR, NC, D + 1, FR, FC, FD))
			{
				FR = NR;
				FC = NC;
				FD = D + 1;
			}
			else
			{
				SQ.emplace(p(NR, NC), D + 1);
			}
		}
	}

	return pp(p(FR, FC), FD);
}

bool EatFish()
{
	pp Min = BFS();
	if (Min.second == 1000)
	{
		return false;
	}

	Bowl[Row][Col] = 0;

	Row = Min.first.first;
	Col = Min.first.second;
	Bowl[Row][Col] = 9;
	Time += Min.second;

	++Ate;
	if (Ate == Size)
	{
		Ate = 0;
		++Size;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Bowl[i][j];
			if (Bowl[i][j] == 9)
			{
				Row = i;
				Col = j;
			}
		}
	}

	while (EatFish()) {}
	cout << Time;
}