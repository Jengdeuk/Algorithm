#include <iostream>
using namespace std;

const int DX[4] = { 0, 1, 0, -1 };
const int DY[4] = { -1, 0, 1, 0 };

int N, M;
int Room[50][50];

bool DetectNewArea(int R, int C)
{
	for (int i = 0; i < 4; ++i)
	{
		int NR = R + DY[i];
		int NC = C + DX[i];
		if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1 || Room[NR][NC] != 0)
		{
			continue;
		}

		return true;
	}

	return false;
}

void TurnLeft(int& D)
{
	D = (D - 1 >= 0 ? D - 1 : 3);
}

bool DontGo(int R, int C, int D)
{
	int NR = R + DY[D];
	int NC = C + DX[D];
	if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1 || Room[NR][NC] != 0)
	{
		return true;
	}

	return false;
}

int CleanRoom(int SR, int SC, int SD)
{
	int Cnt = 0;
	int R = SR, C = SC, D = SD;

	while (true)
	{
		if (Room[R][C] == 0)
		{
			Room[R][C] = 3;
			++Cnt;
		}

		if (DetectNewArea(R, C))
		{
			do
			{
				TurnLeft(D);
			} while (DontGo(R, C, D));

			R = R + DY[D];
			C = C + DX[D];
			continue;
		}
		else
		{
			int NR = R - DY[D];
			int NC = C - DX[D];
			if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1 || Room[NR][NC] == 1)
			{
				break;
			}

			R = NR;
			C = NC;
			continue;
		}
	}

	return Cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	int R, C, D;
	cin >> R >> C >> D;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> Room[i][j];
		}
	}

	cout << CleanRoom(R, C, D);
}