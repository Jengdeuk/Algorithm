#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> p;

const int N = 4;
const int M = 4;
const int FishNum = 17;

const int DX[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };
const int DY[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };

p Map[N][M], Fish[FishNum];
int Eat, Max;

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M);
}

void MoveFish()
{
	for (int i = 1; i < FishNum; ++i)
	{
		int FR = Fish[i].first;
		int FC = Fish[i].second;
		if (FR < 0 && FC < 0)
		{
			continue;
		}

		int FD = Map[FR][FC].second;

		int NR, NC;
		while (true)
		{
			NR = FR + DY[FD];
			NC = FC + DX[FD];
			if (IsValid(NR, NC) && Map[NR][NC].first < 17)
			{
				break;
			}

			FD = (FD + 1 == 8 ? 0 : FD + 1);
		}

		Fish[i] = p(NR, NC);
		Fish[Map[NR][NC].first] = p(FR, FC);

		p Temp = Map[NR][NC];
		Map[NR][NC].first = i;
		Map[NR][NC].second = FD;
		Map[FR][FC] = Temp;
	}
}

void Btk(int R, int C)
{
	Fish[Map[R][C].first] = p(-1, -1);
	Map[R][C].first = 17;
	int Dir = Map[R][C].second;

	MoveFish();

	queue<p> NQ;
	for (int i = 1; i <= 3; ++i)
	{
		int NR = R + DY[Dir] * i;
		int NC = C + DX[Dir] * i;
		if (IsValid(NR, NC) && Map[NR][NC].first > 0)
		{
			NQ.emplace(NR, NC);
		}
	}

	if (NQ.empty())
	{
		Max = max(Max, Eat);
		return;
	}

	while (!NQ.empty())
	{
		int NR = NQ.front().first;
		int NC = NQ.front().second;
		NQ.pop();

		p Temp[N][M] = {};
		p TempFish[FishNum] = {};
		memcpy(Temp, Map, sizeof(Temp));
		memcpy(TempFish, Fish, sizeof(TempFish));

		Map[R][C].first = 0;
		Eat += Map[NR][NC].first;
		Btk(NR, NC);

		memcpy(Map, Temp, sizeof(Map));
		memcpy(Fish, TempFish, sizeof(Fish));
		Eat -= Map[NR][NC].first;
		Fish[Map[NR][NC].first] = p(NR, NC);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Map[i][j].first >> Map[i][j].second;
			--Map[i][j].second;
			Fish[Map[i][j].first] = p(i, j);
		}
	}

	Eat = Map[0][0].first;
	Fish[Map[0][0].first] = p(-1, -1);
	Btk(0, 0);

	cout << Max;
}