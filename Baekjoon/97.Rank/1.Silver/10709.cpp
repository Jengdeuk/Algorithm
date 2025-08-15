#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int N, M, T[100][100];

queue<p> CQ;

void RecordTimeAndMoveCloud(int Time)
{
	queue<p> NQ;

	while (CQ.empty() == false)
	{
		int R = CQ.front().first;
		int C = CQ.front().second;
		CQ.pop();

		if (T[R][C] == -1)
		{
			T[R][C] = Time;
		}

		if (C + 1 < M)
		{
			NQ.emplace(R, C + 1);
		}
	}

	CQ.swap(NQ);
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
			T[i][j] = -1;

			char Ch;
			cin >> Ch;
			if (Ch == 'c')
			{
				CQ.emplace(i, j);
			}
		}
	}

	int Time = 0;
	while (CQ.empty() == false)
	{
		RecordTimeAndMoveCloud(Time++);
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << T[i][j] << ' ';
		}
		cout << '\n';
	}
}