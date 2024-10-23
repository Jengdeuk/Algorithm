#include <iostream>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, int> pi;

const int DX[4] = { 0, 0, -1, 1 };
const int DY[4] = { -1, 1, 0, 0 };

int N, M, K;
int MapShark[20][20];
p MapSmell[20][20];
bool Dead[401];
pi Shark[401];
int Priority[401][4][4];

void SpraySmell()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (MapSmell[i][j].second > 0)
			{
				if (--MapSmell[i][j].second == 0)
				{
					MapSmell[i][j].first = 0;
				}
			}
		}
	}

	for (int i = M; i >= 1; --i)
	{
		if (Dead[i])
		{
			continue;
		}

		int R = Shark[i].first.first;
		int C = Shark[i].first.second;
		MapSmell[R][C].first = i;
		MapSmell[R][C].second = K;
	}
}

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < N);
}

void MoveShark()
{
	for (int i = M; i >= 1; --i)
	{
		if (Dead[i])
		{
			continue;
		}

		int R = Shark[i].first.first;
		int C = Shark[i].first.second;
		int D = Shark[i].second;

		bool bFound = false;
		for (int j = 0; j < 4; ++j)
		{
			int Dir = Priority[i][D][j];
			int NR = R + DY[Dir];
			int NC = C + DX[Dir];
			if (IsValid(NR, NC) && MapSmell[NR][NC].first == 0)
			{
				bFound = true;
				if (MapShark[NR][NC] > 0)
				{
					Dead[MapShark[NR][NC]] = true;
				}

				MapShark[R][C] = 0;
				MapShark[NR][NC] = i;
				Shark[i].first = p(NR, NC);
				Shark[i].second = Dir;
				break;
			}
		}

		if (bFound)
		{
			continue;
		}

		for (int j = 0; j < 4; ++j)
		{
			int Dir = Priority[i][D][j];
			int NR = R + DY[Dir];
			int NC = C + DX[Dir];
			if (IsValid(NR, NC) && MapSmell[NR][NC].first == i)
			{
				MapShark[R][C] = 0;
				MapShark[NR][NC] = i;
				Shark[i].first = p(NR, NC);
				Shark[i].second = Dir;
				break;
			}
		}
	}
}

bool IsFinished()
{
	for (int i = 2; i <= M; ++i)
	{
		if (!Dead[i])
		{
			return false;
		}
	}

	return true;
}

bool Tick()
{
	MoveShark();
	SpraySmell();

	return IsFinished();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int Num;
			cin >> Num;
			if (Num > 0)
			{
				MapShark[i][j] = Num;
				Shark[Num].first = p(i, j);
			}
		}
	}

	for (int i = 1; i <= M; ++i)
	{
		int Dir;
		cin >> Dir;
		Shark[i].second = Dir - 1;
	}

	for (int i = 1; i <= M; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				int Dir;
				cin >> Dir;
				Priority[i][j][k] = Dir - 1;
			}
		}
	}

	int T = 1;
	while (T <= 1000)
	{
		if (T == 1)
		{
			SpraySmell();
		}

		if (Tick())
		{
			break;
		}

		++T;
	}

	if (T <= 1000)
	{
		cout << T;
	}
	else
	{
		cout << -1;
	}
}