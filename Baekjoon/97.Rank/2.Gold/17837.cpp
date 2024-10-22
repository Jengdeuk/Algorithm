#include <iostream>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, p> pp;

const int DX[4] = { 1, -1, 0, 0 };
const int DY[4] = { 0, 0, -1, 1 };

int N, K;
int M[12][12];
pp H[11];

void PutOffTop(int Cur)
{
	for (int i = 1; i <= K; ++i)
	{
		if (H[i].second.second == Cur)
		{
			H[i].second.second = 0;
		}
	}
}

void PutOnTop(int Cur, int Bot, int R, int C)
{
	for (int i = 1; i <= K; ++i)
	{
		if (i == Cur)
		{
			continue;
		}

		if (H[i].first.first == R && H[i].first.second == C && H[i].second.second == 0)
		{
			H[i].second.second = Bot;
			break;
		}
	}
}

void WhiteBlock(int Cur)
{
	int R = H[Cur].first.first;
	int C = H[Cur].first.second;
	int D = H[Cur].second.first;

	int NR = R + DY[D];
	int NC = C + DX[D];
	H[Cur].first = p(NR, NC);
	PutOffTop(Cur);
	PutOnTop(Cur, Cur, NR, NC);

	int U = H[Cur].second.second;
	while (U != 0)
	{
		H[U].first = p(NR, NC);
		U = H[U].second.second;
	}
}

void RedBlock(int Cur)
{
	int R = H[Cur].first.first;
	int C = H[Cur].first.second;
	int D = H[Cur].second.first;

	int NR = R + DY[D];
	int NC = C + DX[D];
	H[Cur].first = p(NR, NC);
	PutOffTop(Cur);

	int U = H[Cur].second.second;
	H[Cur].second.second = 0;
	int P = Cur;
	while (U != 0)
	{
		int Temp = U;
		H[Temp].first = p(NR, NC);
		U = H[Temp].second.second;
		H[Temp].second.second = P;
		P = Temp;
	}

	PutOnTop(Cur, P, NR, NC);
}

int GetColor(int R, int C)
{
	if (R < 0 || R >= N || C < 0 || C >= N)
	{
		return 2;
	}

	return M[R][C];
}

void ChangeDir(int Cur)
{
	if (H[Cur].second.first % 2 == 0)
	{
		++H[Cur].second.first;
	}
	else
	{
		--H[Cur].second.first;
	}
}

bool IsFinished()
{
	int Count[12][12] = {};
	for (int i = 1; i <= K; ++i)
	{
		if (++Count[H[i].first.first][H[i].first.second] >= 4)
		{
			return true;
		}
	}

	return false;
}

bool Tick()
{
	for (int i = 1; i <= K; ++i)
	{
		int R = H[i].first.first, C = H[i].first.second;
		int NR = R + DY[H[i].second.first];
		int NC = C + DX[H[i].second.first];
		switch (GetColor(NR, NC))
		{
		case 0:
			WhiteBlock(i);
			break;

		case 1:
			RedBlock(i);
			break;

		case 2:
			ChangeDir(i);
			NR = R + DY[H[i].second.first];
			NC = C + DX[H[i].second.first];
			switch (GetColor(NR, NC))
			{
			case 0:
				WhiteBlock(i);
				break;

			case 1:
				RedBlock(i);
				break;
			}

			break;
		}

		if (IsFinished())
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> M[i][j];
		}
	}

	for (int i = 1; i <= K; ++i)
	{
		int R, C, D;
		cin >> R >> C >> D;
		H[i].first.first = R - 1;
		H[i].first.second = C - 1;
		H[i].second.first = D - 1;
	}

	int T = 1;
	while (T <= 1000)
	{
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