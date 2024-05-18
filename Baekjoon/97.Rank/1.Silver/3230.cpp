#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> Rank, Rank2;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		int R;
		cin >> R;
		if (R <= Rank.size())
		{
			Rank.insert(Rank.begin() + R - 1, i);
		}
		else
		{
			Rank.emplace_back(i);
		}
	}

	for (int i = M - 1; i >= 0; --i)
	{
		Rank2.emplace_back(Rank[i]);
	}

	Rank.clear();
	for (int i = 0; i < M; ++i)
	{
		int R;
		cin >> R;
		if (R <= Rank.size())
		{
			Rank.insert(Rank.begin() + R - 1, Rank2[i]);
		}
		else
		{
			Rank.emplace_back(Rank2[i]);
		}
	}

	for (int i = 0; i < 3; ++i)
	{
		cout << Rank[i] << '\n';
	}
}