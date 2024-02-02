#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> Distance;

void FloydWarshall(int N)
{
	for (int K = 0; K < N; ++K)
	{
		for (int Start = 0; Start < N; ++Start)
		{
			for (int End = 0; End < N; ++End)
			{
				if (Distance[Start][K] == 0
					|| Distance[K][End] == 0)
				{
					continue;
				}

				Distance[Start][End] = 1;
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	Distance.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		Distance.emplace_back(vector<int>());

		for (int j = 0; j < N; ++j)
		{
			int Edge;
			cin >> Edge;

			Distance.back().emplace_back(Edge);
		}
	}

	FloydWarshall(N);

	for (const vector<int>& Row : Distance)
	{
		for (const int& Edge : Row)
		{
			cout << Edge << ' ';
		}
		cout << '\n';
	}
}