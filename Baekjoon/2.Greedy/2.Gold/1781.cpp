#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N;
p S[200000];

bool Compare(const p& L, const p& R)
{
	return (L.first == R.first ? L.second > R.second : L.first > R.first);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i].first >> S[i].second;
	}

	sort(S, S + N, Compare);

	int Sum = 0, Idx = 0;
	priority_queue<int> Q;
	for (int i = N; i >= 1; --i)
	{
		while (S[Idx].first == i)
		{
			Q.emplace(S[Idx++].second);
		}

		if (!Q.empty())
		{
			Sum += Q.top();
			Q.pop();
		}
	}

	cout << Sum;
}