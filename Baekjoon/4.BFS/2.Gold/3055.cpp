#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M;
char Map[50][50];
bool Vst[50][50];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M);
}

bool IsCanGo(int R, int C)
{
	return (!Vst[R][C] && Map[R][C] != '*' && Map[R][C] != 'X');
}

int BFS()
{
	p Start;

	queue<ip> Q;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] == '*')
			{
				Q.emplace(-1, p(i, j));
			}

			if (Map[i][j] == 'S')
			{
				Start = p(i, j);
			}
		}
	}

	Vst[Start.first][Start.second] = true;
	Q.emplace(0, Start);
	while (!Q.empty())
	{
		int T = Q.front().first;
		int R = Q.front().second.first;
		int C = Q.front().second.second;
		Q.pop();

		if (T < 0)
		{
			for (int i = 0; i < 4; ++i)
			{
				int NR = R + DY[i];
				int NC = C + DX[i];
				if (IsValid(NR, NC) && (Map[NR][NC] == '.' || Map[NR][NC] == 'S'))
				{
					Map[NR][NC] = '*';
					Q.emplace(-1, p(NR, NC));
				}
			}
		}
		else
		{
			if (Map[R][C] == 'D')
			{
				return T;
			}

			for (int i = 0; i < 4; ++i)
			{
				int NR = R + DY[i];
				int NC = C + DX[i];
				if (IsValid(NR, NC) && IsCanGo(NR, NC))
				{
					Vst[NR][NC] = true;
					Q.emplace(T + 1, p(NR, NC));
				}
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string Str;
		cin >> Str;

		for (int j = 0; j < M; ++j)
		{
			char Ch = Str[j];
			Map[i][j] = Ch;
		}
	}

	int T = BFS();
	if (T < 0)
	{
		cout << "KAKTUS";
		return 0;
	}

	cout << T;
}