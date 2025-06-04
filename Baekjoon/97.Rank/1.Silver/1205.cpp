#include <iostream>
using namespace std;

typedef pair<int, int> p;

int N, P;
p S[52];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Score;
	cin >> N >> Score >> P;

	int Rank = 1;
	for (int i = 1; i <= N; ++i)
	{
		cin >> S[i].second;
		if (S[i].second < S[i - 1].second)
		{
			Rank = i;
		}
		S[i].first = Rank;
	}

	Rank = N + 1;
	for (int i = 1; i <= N; ++i)
	{
		if (Score >= S[i].second)
		{
			Rank = S[i].first;
			break;
		}
	}

	if ((Rank != P + 1 && (Rank == S[P].first && Score == S[P].second) == false) || N == 0)
	{
		cout << Rank;
	}
	else
	{
		cout << -1;
	}
}