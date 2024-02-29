#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int& Infinite = INT_MAX;

vector<vector<int>> Distance;

void FloydWarshall(int N)
{
	for (int K = 0; K < N; ++K)
	{
		for (int Start = 0; Start < N; ++Start)
		{
			for (int End = 0; End < N; ++End)
			{
				if (Distance[Start][K] == Infinite
					|| Distance[K][End] == Infinite)
				{
					continue;
				}

				Distance[Start][End] = min(Distance[Start][End], Distance[Start][K] + Distance[K][End]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	Distance.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		Distance.emplace_back(vector<int>(N, Infinite));
		Distance[i][i] = 0;
	}

	for (int i = 0; i < M; ++i)
	{
		int Start, End, Weight;
		cin >> Start >> End >> Weight;

		Distance[Start - 1][End - 1] = min(Distance[Start - 1][End - 1], Weight);
	}

	FloydWarshall(N);

	for (const vector<int>& Row : Distance)
	{
		for (const int& Weight : Row)
		{
			if (Weight == Infinite)
			{
				cout << 0;
			}
			else
			{
				cout << Weight;
			}
			cout << ' ';
		}
		cout << '\n';
	}
}