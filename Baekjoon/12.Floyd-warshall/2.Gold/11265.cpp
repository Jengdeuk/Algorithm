#include <iostream>
using namespace std;

int N, M;
int Time[501][501];

void FloydWarshall()
{
	for (int k = 1; k <= N; ++k)
	{
		for (int s = 1; s <= N; ++s)
		{
			for (int e = 1; e <= N; ++e)
			{
				Time[s][e] = min(Time[s][e], Time[s][k] + Time[k][e]);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cin >> Time[i][j];
		}
	}

	FloydWarshall();

	for (int i = 0; i < M; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		if (Time[A][B] <= C)
		{
			cout << "Enjoy other party\n";
		}
		else
		{
			cout << "Stay here\n";
		}
	}
}