#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int Cos = 0;
const int Sin = 1;

const int DX[4] = { 1, 0, -1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

bool DC[101][101];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < 101 && C >= 0 && C < 101);
}

void Render()
{
	int SX, SY, D, G;
	cin >> SX >> SY >> D >> G;

	int EX = SX + DX[D], EY = SY + DY[D];

	vector<p> Dragon;
	Dragon.emplace_back(SX, SY);
	Dragon.emplace_back(EX, EY);
	for (int i = 0; i < G; ++i)
	{
		queue<p> Q;
		for (const p& Vertex : Dragon)
		{
			if (Vertex.first == EX && Vertex.second == EY)
			{
				continue;
			}

			Q.emplace(Vertex);
		}

		int NEX = EX, NEY = EY;
		while (!Q.empty())
		{
			int X = Q.front().first;
			int Y = Q.front().second;
			Q.pop();

			int NX = (X - EX) * Cos - (Y - EY) * Sin + EX;
			int NY = (X - EX) * Sin + (Y - EY) * Cos + EY;
			Dragon.emplace_back(NX, NY);

			if (X == SX && Y == SY)
			{
				NEX = NX, NEY = NY;
			}
		}

		EX = NEX, EY = NEY;
	}

	for (const p& Vertex : Dragon)
	{
		int R = Vertex.second, C = Vertex.first;
		if (IsValid(R, C))
		{
			DC[R][C] = true;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		Render();
	}

	int Cnt = 0;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 100; ++j)
		{
			if (DC[i][j] && DC[i][j + 1] && DC[i + 1][j] && DC[i + 1][j + 1])
			{
				++Cnt;
			}
		}
	}

	cout << Cnt;
}