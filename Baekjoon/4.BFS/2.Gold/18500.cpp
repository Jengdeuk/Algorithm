#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
bool Mrl[100][100], V[100][100];
vector<p> FMrl, PMrl;

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M && V[R][C] == false && Mrl[R][C]);
}

bool BFS(int SR, int SC)
{
	bool bGroundAttached = false;
	vector<p>().swap(FMrl);
	FMrl.reserve(10000);

	vector<p>().swap(PMrl);
	PMrl.reserve(10000);

	queue<p> Q;
	V[SR][SC] = true;
	Q.emplace(SR, SC);
	while (Q.empty() == false)
	{
		int R = Q.front().first;
		int C = Q.front().second;
		Q.pop();

		if (R == N - 1)
		{
			bGroundAttached = true;
		}

		FMrl.emplace_back(R, C);
		if (Mrl[R + 1][C] == false)
		{
			PMrl.emplace_back(R, C);
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsValid(NR, NC))
			{
				V[NR][NC] = true;
				Q.emplace(NR, NC);
			}
		}
	}

	return (bGroundAttached == false);
}

bool ThrowAndBreak(int H, int Dir)
{
	int R = H, C = (Dir == 1 ? 0 : M - 1), EC = (Dir == 1 ? M : -1);
	while (C != EC && Mrl[R][C] == false)
	{
		C += Dir;
	}

	bool bBreak = false;
	if (C != EC && Mrl[R][C])
	{
		bBreak = true;
		Mrl[R][C] = false;
	}

	if (bBreak)
	{
		memset(V, false, sizeof(V));
		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsValid(NR, NC) == false)
			{
				continue;
			}

			if (BFS(NR, NC))
			{
				for (const p& FM : FMrl)
				{
					Mrl[FM.first][FM.second] = false;
				}

				return true;
			}
		}
	}

	return false;
}

void Falling()
{
	int H = 100;
	for (const p& PM : PMrl)
	{
		for (int i = 1; i <= N; ++i)
		{
			int NR = PM.first + i;
			if (NR >= N || Mrl[NR][PM.second])
			{
				H = min(H, i - 1);
				break;
			}
		}
	}

	for (const p& FM : FMrl)
	{
		Mrl[FM.first + H][FM.second] = true;
	}
}

void Print()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Mrl[i][j])
			{
				cout << 'x';
			}
			else
			{
				cout << '.';
			}
		}
		cout << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		for (int j = 0; j < M; ++j)
		{
			Mrl[i][j] = (S[j] == 'x');
		}
	}

	int Q;
	cin >> Q;

	int Dir = 1;
	while (Q--)
	{
		int H;
		cin >> H;
		H = N - H;

		if (ThrowAndBreak(H, Dir))
		{
			Falling();
		}

		Dir = (Dir == 1 ? -1 : 1);
	}

	Print();
}