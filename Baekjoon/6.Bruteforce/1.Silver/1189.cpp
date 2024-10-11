#include <iostream>
#include <string>
using namespace std;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M, K;
bool Wall[5][5];
int Count;
bool V[5][5];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M && !Wall[R][C] && !V[R][C]);
}

void DFS(int Step, int R, int C)
{
	if (R == 0 && C == M - 1)
	{
		if (Step == K)
		{
			++Count;
		}

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int NR = R + DY[i];
		int NC = C + DX[i];
		if (IsValid(NR, NC))
		{
			V[NR][NC] = true;
			DFS(Step + 1, NR, NC);
			V[NR][NC] = false;
		}
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;

		for (int j = 0; j < M; ++j)
		{
			if (S[j] == 'T')
			{
				Wall[i][j] = true;
			}
		}
	}

	V[N - 1][0] = true;
	DFS(1, N - 1, 0);

	cout << Count;
}