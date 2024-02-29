#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> Box;
queue<pair<int, int>> Queue1;
queue<pair<int, int>> Queue2;

int BFS(int N, int M)
{
	int Day = 0;

	while (true)
	{
		while (!Queue1.empty())
		{
			int Row = Queue1.front().first;
			int Col = Queue1.front().second;
			Queue1.pop();

			// Left
			if (Col > 0
				&& Box[Row][Col - 1] == 0)
			{
				Box[Row][Col - 1] = 1;
				Queue2.emplace(Row, Col - 1);
			}

			// Top
			if (Row > 0
				&& Box[Row - 1][Col] == 0)
			{
				Box[Row - 1][Col] = 1;
				Queue2.emplace(Row - 1, Col);
			}

			// Right
			if (Col < M - 1
				&& Box[Row][Col + 1] == 0)
			{
				Box[Row][Col + 1] = 1;
				Queue2.emplace(Row, Col + 1);
			}

			// Bottom
			if (Row < N - 1
				&& Box[Row + 1][Col] == 0)
			{
				Box[Row + 1][Col] = 1;
				Queue2.emplace(Row + 1, Col);
			}
		}

		if (Queue2.empty())
		{
			return Day;
		}

		++Day;

		while (!Queue2.empty())
		{
			int Row = Queue2.front().first;
			int Col = Queue2.front().second;
			Queue2.pop();

			// Left
			if (Col > 0
				&& Box[Row][Col - 1] == 0)
			{
				Box[Row][Col - 1] = 1;
				Queue1.emplace(Row, Col - 1);
			}

			// Top
			if (Row > 0
				&& Box[Row - 1][Col] == 0)
			{
				Box[Row - 1][Col] = 1;
				Queue1.emplace(Row - 1, Col);
			}

			// Right
			if (Col < M - 1
				&& Box[Row][Col + 1] == 0)
			{
				Box[Row][Col + 1] = 1;
				Queue1.emplace(Row, Col + 1);
			}

			// Bottom
			if (Row < N - 1
				&& Box[Row + 1][Col] == 0)
			{
				Box[Row + 1][Col] = 1;
				Queue1.emplace(Row + 1, Col);
			}
		}

		if (Queue1.empty())
		{
			return Day;
		}

		++Day;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int M, N;
	cin >> M >> N;

	Box.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		Box.emplace_back(vector<int>());

		for (int j = 0; j < M; ++j)
		{
			int Tomato;
			cin >> Tomato;
			Box.back().emplace_back(Tomato);

			if (Tomato == 1)
			{
				Queue1.emplace(i, j);
			}
		}
	}

	int Day = BFS(N, M);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Box[i][j] == 0)
			{
				Day = -1;
				cout << Day;
				return 0;
			}
		}
	}

	cout << Day;
}