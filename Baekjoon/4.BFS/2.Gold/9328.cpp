#include <iostream>
#include <cstring>
#include <string>
#include <queue>
using namespace std;

int N, M;
char Map[100][100];

int Document;
bool bRepeat;
bool Visited[100][100];

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

void OpenDoor(char Key)
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] == Key - 32)
			{
				bRepeat = true;
				Map[i][j] = '.';
			}
			else if (Map[i][j] == Key)
			{
				Map[i][j] = '.';
			}
		}
	}

	memset(Visited, false, sizeof(Visited));
}

void BFS(int SR, int SC)
{
	if (Visited[SR][SC])
	{
		return;
	}

	queue<pair<int, int>> SQ;
	Visited[SR][SC] = true;
	SQ.emplace(SR, SC);
	while (!SQ.empty())
	{
		int R = SQ.front().first;
		int C = SQ.front().second;
		SQ.pop();

		char Ch = Map[R][C];
		if (Ch >= 'a' && Ch <= 'z')
		{
			OpenDoor(Ch);
			Map[R][C] = '.';
			Visited[R][C] = true;
		}
		else if (Ch == '$')
		{
			++Document;
			Map[R][C] = '.';
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1
				|| Map[NR][NC] == '*'
				|| (Map[NR][NC] >= 'A' && Map[NR][NC] <= 'Z')
				|| Visited[NR][NC])
			{
				continue;
			}

			Visited[NR][NC] = true;
			SQ.emplace(NR, NC);
		}
	}
}

void Test()
{
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string Str;
		cin >> Str;
		for (int j = 0; j < M; ++j)
		{
			Map[i][j] = Str[j];
		}
	}

	string Keys;
	cin >> Keys;
	for (int i = 0; i < Keys.size(); ++i)
	{
		char Key = Keys[i];
		if (Key != '0')
		{
			OpenDoor(Key);
		}
	}

	Document = 0;
	bRepeat = true;
	memset(Visited, false, sizeof(Visited));
	while (bRepeat)
	{
		bRepeat = false;

		char Ch;
		for (int j = 0; j < M; ++j)
		{
			Ch = Map[0][j];
			if (Ch != '*' && !(Ch >= 'A' && Ch <= 'Z'))
			{
				BFS(0, j);
			}

			Ch = Map[N - 1][j];
			if (Ch != '*' && !(Ch >= 'A' && Ch <= 'Z'))
			{
				BFS(N - 1, j);
			}
		}

		for (int i = 0; i < N; ++i)
		{
			Ch = Map[i][0];
			if (Ch != '*' && !(Ch >= 'A' && Ch <= 'Z'))
			{
				BFS(i, 0);
			}

			Ch = Map[i][M - 1];
			if (Ch != '*' && !(Ch >= 'A' && Ch <= 'Z'))
			{
				BFS(i, M - 1);
			}
		}
	}

	cout << Document << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}