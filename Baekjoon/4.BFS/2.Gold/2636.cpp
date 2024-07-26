#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
bool Cheese[100][100];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M);
}

void Melt()
{
	bool V[100][100] = {};

	queue<p> Q;
	V[0][0] = true;
	Q.emplace(0, 0);
	while (!Q.empty())
	{
		int R = Q.front().first;
		int C = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (!IsValid(NR, NC) || V[NR][NC])
			{
				continue;
			}
			
			V[NR][NC] = true;
			if (Cheese[NR][NC])
			{
				Cheese[NR][NC] = false;
			}
			else
			{
				Q.emplace(NR, NC);
			}
		}
	}
}

int Count()
{
	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Cheese[i][j])
			{
				++Cnt;
			}
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
		for (int j = 0; j < M; ++j)
		{
			cin >> Cheese[i][j];
		}
	}

	int Time = 0, Answer = 0;

	int Remainder;
	while ((Remainder = Count()) > 0)
	{
		Answer = Remainder;

		Melt();
		++Time;
	}

	cout << Time << '\n';
	cout << Answer;
}