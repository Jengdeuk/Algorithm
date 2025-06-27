#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
char B[1000][1000];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M && B[R][C] != '#' && B[R][C] != '*');
}

int BFS(int SR, int SC)
{
	queue<ip> Q;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (B[i][j] == '*')
			{
				Q.emplace(0, p(i, j));
			}
		}
	}

	bool V[1000][1000] = {};
	V[SR][SC] = true;
	Q.emplace(1, p(SR, SC));
	while (Q.empty() == false)
	{
		int T = Q.front().first;
		int R = Q.front().second.first;
		int C = Q.front().second.second;
		Q.pop();

		if (T > 0 && (R == 0 || R == N - 1 || C == 0 || C == M - 1))
		{
			return T;
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (T == 0)
			{
				if (IsValid(NR, NC))
				{
					B[NR][NC] = '*';
					Q.emplace(T, p(NR, NC));
				}
			}
			else
			{
				if (IsValid(NR, NC) && V[NR][NC] == false)
				{
					V[NR][NC] = true;
					Q.emplace(T + 1, p(NR, NC));
				}
			}
		}
	}

	return -1;
}

void Test()
{
	cin >> M >> N;

	int SR = 0, SC = 0;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;

		for (int j = 0; j < M; ++j)
		{
			if (S[j] == '@')
			{
				SR = i;
				SC = j;
				B[i][j] = '.';
				continue;
			}

			B[i][j] = S[j];
		}
	}

	int T = BFS(SR, SC);
	if (T >= 0)
	{
		cout << T;
	}
	else
	{
		cout << "IMPOSSIBLE";
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) Test();
}