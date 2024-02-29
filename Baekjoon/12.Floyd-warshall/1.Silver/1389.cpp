#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

const int Infinite = INT_MAX;

int Distance[101][101];

vector<pair<int, int>> OrderedList;
bool Compare(const pair<int, int>& Left, const pair<int, int>& Right)
{
	return (Left.second == Right.second) ? Left.first < Right.first : Left.second < Right.second;
}

int N, M;
void FloydWarshall()
{
	for (int K = 1; K <= N; ++K)
	{
		for (int S = 1; S <= N; ++S)
		{
			if (Distance[S][K] == Infinite)
			{
				continue;
			}

			for (int E = 1; E <= N; ++E)
			{
				if (Distance[K][E] == Infinite)
				{
					continue;
				}

				Distance[S][E] = min(Distance[S][E], Distance[S][K] + Distance[K][E]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i != j)
			{
				Distance[i][j] = Infinite;
			}
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;

		Distance[A][B] = 1;
		Distance[B][A] = 1;
	}

	FloydWarshall();

	for (int i = 1; i <= N; ++i)
	{
		int Count = 0;
		for (int j = 1; j <= N; ++j)
		{
			Count += Distance[i][j];
		}
		OrderedList.emplace_back(i, Count);
	}

	cout << (*min_element(OrderedList.begin(), OrderedList.end(), Compare)).first;
}