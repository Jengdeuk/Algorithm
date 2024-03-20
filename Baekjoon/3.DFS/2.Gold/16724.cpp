#include <iostream>
#include <string>
using namespace std;

int N, M, Cnt;
char Map[1000][1000];
bool Visited[1000][1000];
bool Check[1000][1000];

void DFS(int Row, int Col)
{
	Visited[Row][Col] = true;

	int NR = Row, NC = Col;
	switch (Map[Row][Col])
	{
	case 'U':
		--NR;
		break;

	case 'D':
		++NR;
		break;

	case 'L':
		--NC;
		break;

	case 'R':
		++NC;
		break;
	}

	if (!Visited[NR][NC])
	{
		DFS(NR, NC);
	}
	else if (!Check[NR][NC])
	{
		++Cnt;
	}

	Check[Row][Col] = true;
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
			Map[i][j] = Str[j];
		}
	}

	Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!Check[i][j])
			{
				DFS(i, j);
			}
		}
	}

	cout << Cnt << '\n';
}