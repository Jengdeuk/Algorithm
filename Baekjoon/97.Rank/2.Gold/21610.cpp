#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int DX[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int DY[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int N, W[50][50], V[50][50];
queue<p> Cloud;

void MoveAndRain()
{
	memset(V, false, sizeof(V));

	int D, S;
	cin >> D >> S;
	D--;

	while (Cloud.empty() == false)
	{
		int R = Cloud.front().first + DY[D] * S;
		int C = Cloud.front().second + DX[D] * S;
		Cloud.pop();

		R %= N;
		C %= N;

		if (R < 0)
		{
			R += N;
		}

		if (C < 0)
		{
			C += N;
		}

		V[R][C] = true;
		W[R][C]++;
	}
}

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < N);
}

void WaterSpread()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (V[i][j] == false)
			{
				continue;
			}

			for (int k = 1; k <= 7; k += 2)
			{
				int NR = i + DY[k];
				int NC = j + DX[k];
				if (IsValid(NR, NC))
				{
					W[i][j] += (W[NR][NC] > 0);
				}
			}
		}
	}
}

void MakeNewCloud()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (V[i][j] || W[i][j] < 2)
			{
				continue;
			}

			W[i][j] -= 2;
			Cloud.emplace(i, j);
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> W[i][j];
		}
	}

	Cloud.emplace(N - 1, 0);
	Cloud.emplace(N - 1, 1);
	Cloud.emplace(N - 2, 0);
	Cloud.emplace(N - 2, 1);

	while (M--)
	{
		MoveAndRain();
		WaterSpread();
		MakeNewCloud();
	}

	int Water = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Water += W[i][j];
		}
	}

	cout << Water;
}