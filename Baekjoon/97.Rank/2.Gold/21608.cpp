#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<bool, p> bp;
typedef pair<int, p> ip;

const int SC[5] = { 0, 1, 10, 100, 1000 };
const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, Score;
int S, F[401][4];
int Map[20][20];
bp Sit[401];

bool IsInvalid(int R, int C)
{
	return (R < 0 || R > N - 1 || C < 0 || C > N - 1);
}

bool Comp(const ip& L, const ip& R)
{
	return (L.first == R.first ? (L.second.first == R.second.first ? L.second.second < R.second.second : L.second.first < R.second.first) : L.first > R.first);
}

void Input()
{
	cin >> S;
	for (int f = 0; f < 4; ++f)
	{
		cin >> F[S][f];
	}
}

void SetPlace()
{
	if (S == 9)
	{
		int a = 0;
	}

	int BNum = 0, MaxFriendsCnt = 0;
	ip Blank[16];
	for (int f = 0; f < 4; ++f)
	{
		if (!Sit[F[S][f]].first)
		{
			continue;
		}
		
		int R = Sit[F[S][f]].second.first;
		int C = Sit[F[S][f]].second.second;
		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsInvalid(NR, NC) || Map[NR][NC])
			{
				continue;
			}

			int Cnt = 0;
			for (int j = 0; j < 4; ++j)
			{
				int NNR = NR + DY[j];
				int NNC = NC + DX[j];
				if (IsInvalid(NNR, NNC) || Map[NNR][NNC] == 0)
				{
					continue;
				}

				for (int k = 0; k < 4; ++k)
				{
					if (Map[NNR][NNC] == F[S][k])
					{
						++Cnt;
						break;
					}
				}
			}

			MaxFriendsCnt = max(MaxFriendsCnt, Cnt);
			Blank[BNum].first = Cnt;
			Blank[BNum++].second = p(NR, NC);
		}
	}
	
	if (BNum == 0)
	{
		int Temp[20][20] = {};

		int MaxCnt = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (Map[i][j])
				{
					continue;
				}

				int Cnt = 0;
				for (int k = 0; k < 4; ++k)
				{
					int NR = i + DY[k];
					int NC = j + DX[k];
					if (IsInvalid(NR, NC) || Map[NR][NC])
					{
						continue;
					}

					++Cnt;
				}

				MaxCnt = max(MaxCnt, Cnt);
				Temp[i][j] = Cnt;
			}
		}

		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (Map[i][j] == 0 && Temp[i][j] == MaxCnt)
				{
					Sit[S].first = true;
					Sit[S].second = p(i, j);
					Map[i][j] = S;
					return;
				}
			}
		}
	}

	sort(Blank, Blank + BNum, greater<>());

	int SNum = 0;
	for (int i = 0; i < BNum; ++i)
	{
		if (Blank[i].first != MaxFriendsCnt)
		{
			break;
		}

		++SNum;
	}

	if (SNum == 1)
	{
		Sit[S].first = true;
		Sit[S].second = Blank[0].second;
		Map[Blank[0].second.first][Blank[0].second.second] = S;
		return;
	}

	int MaxCnt = 0;
	ip Temp[16] = {};
	for (int i = 0; i < SNum; ++i)
	{
		int R = Blank[i].second.first;
		int C = Blank[i].second.second;

		int Cnt = 0;
		for (int k = 0; k < 4; ++k)
		{
			int NR = R + DY[k];
			int NC = C + DX[k];
			if (IsInvalid(NR, NC) || Map[NR][NC])
			{
				continue;
			}

			++Cnt;
		}

		MaxCnt = max(MaxCnt, Cnt);
		Temp[i].first = Cnt;
		Temp[i].second = Blank[i].second;
	}

	sort(Temp, Temp + SNum, Comp);

	Sit[S].first = true;
	Sit[S].second = Temp[0].second;
	Map[Temp[0].second.first][Temp[0].second.second] = S;
}

void AddScore()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int Cnt = 0;

			S = Map[i][j];
			int R = Sit[S].second.first;
			int C = Sit[S].second.second;
			for (int i = 0; i < 4; ++i)
			{
				int NR = R + DY[i];
				int NC = C + DX[i];
				if (IsInvalid(NR, NC) || Map[NR][NC] == 0)
				{
					continue;
				}

				for (int f = 0; f < 4; ++f)
				{
					if (Map[NR][NC] == F[S][f])
					{
						++Cnt;
						break;
					}
				}
			}

			Score += SC[Cnt];
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N * N; ++i)
	{
		Input();
		SetPlace();
	}

	AddScore();

	cout << Score;
}