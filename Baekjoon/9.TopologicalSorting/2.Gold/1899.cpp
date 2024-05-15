#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Neighbor[200001][2];
int Entry[200001];
bool Visited[200001];
vector<int> Sol;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	Sol.reserve(N);

	for (int i = 1; i <= N; ++i)
	{
		int A, B;
		cin >> A >> B;

		Neighbor[i][0] = A;
		++Entry[A];

		Neighbor[i][1] = B;
		++Entry[B];
	}

	bool bRepeat = true;
	while (bRepeat)
	{
		bRepeat = false;
		for (int i = 1; i <= N; ++i)
		{
			if (!Visited[i] && Entry[i] < 2)
			{
				bRepeat = true;
				Visited[i] = true;
				for (int j = 0; j < 2; ++j)
				{
					--Entry[Neighbor[i][j]];
				}
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (Entry[i] == 2)
		{
			Sol.emplace_back(i);
		}
	}

	cout << Sol.size() << '\n';
	for (const int& Elem : Sol)
	{
		cout << Elem << ' ';
	}
}