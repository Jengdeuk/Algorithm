#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;
typedef pair<int, ip> qp;

const int DX[6] = { -1, 0, 1, 0, 0, 0 };
const int DY[6] = { 0, -1, 0, 1, 0, 0 };
const int DZ[6] = { 0, 0, 0, 0, -1, 1 };

int L, N, M;
char B[30][30][30];
bool V[30][30][30];

bool IsValid(int NF, int NR, int NC)
{
	return !(NF < 0 || NF > L - 1 || NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1 || B[NF][NR][NC] == '#' || V[NF][NR][NC]);
}

int BFS(ip S, ip E)
{
	int Time = 0;

	int SF = S.first, SR = S.second.first, SC = S.second.second;
	int EF = E.first, ER = E.second.first, EC = E.second.second;

	memset(V, false, sizeof(V));

	queue<qp> SQ;
	SQ.emplace(0, S);
	V[SF][SR][SC] = true;
	while (!SQ.empty())
	{
		int T = SQ.front().first;
		int F = SQ.front().second.first;
		int R = SQ.front().second.second.first;
		int C = SQ.front().second.second.second;
		SQ.pop();

		if (F == EF && R == ER && C == EC)
		{
			Time = T;
			break;
		}

		for (int i = 0; i < 6; ++i)
		{
			int NF = F + DZ[i];
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsValid(NF, NR, NC))
			{
				SQ.emplace(T + 1, ip(NF, p(NR, NC)));
				V[NF][NR][NC] = true;
			}
		}
	}

	return Time;
}

bool Application()
{
	cin >> L >> N >> M;
	if (L == 0 && N == 0 && M == 0)
	{
		return false;
	}

	ip S, E;
	for (int i = 0; i < L; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			string Str;
			cin >> Str;

			for (int k = 0; k < M; ++k)
			{
				char Ch = Str[k];
				B[i][j][k] = Ch;

				switch (Ch)
				{
				case 'S':
					S = ip(i, p(j, k));
					break;

				case 'E':
					E = ip(i, p(j, k));
					break;
				}
			}
		}
	}

	int Minute = BFS(S, E);
	if (Minute > 0)
	{
		cout << "Escaped in " << Minute << " minute(s).\n";
	}
	else
	{
		cout << "Trapped!\n";
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (Application()) {}
}