#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> jewel;

jewel Jewel[300000];
int Bag[300000];
priority_queue<int> PQ;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		cin >> Jewel[i].first >> Jewel[i].second;
	}

	for (int i = 0; i < K; ++i)
	{
		cin >> Bag[i];
	}

	sort(Jewel, Jewel + N);
	sort(Bag, Bag + K);

	ll Value = 0;
	int Ji = 0;
	for (int i = 0; i < K; ++i)
	{
		int M = Bag[i];
		while (Ji < N && Jewel[Ji].first <= M)
		{
			PQ.emplace(Jewel[Ji].second);
			++Ji;
		}

		if (PQ.empty())
		{
			continue;
		}

		Value += PQ.top();
		PQ.pop();
	}

	cout << Value;
}