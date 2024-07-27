#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int N, D;
p P[100000];

bool Compare(const p& L, const p& R)
{
	return (L.second == R.second ? L.first < R.first : L.second < R.second);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int A, B;
		cin >> A >> B;
		P[i].first = min(A, B);
		P[i].second = max(A, B);
	}
	cin >> D;

	sort(P, P + N, Compare);
	
	priority_queue<int, vector<int>, greater<int>> Q;
	int Max = 0;
	for (int i = 0; i < N; ++i)
	{
		int L = P[i].first;
		int R = P[i].second;
		if (R - L > D)
		{
			continue;
		}

		while (!Q.empty() && Q.top() < R - D)
		{
			Q.pop();
		}

		Q.emplace(L);
		Max = max(Max, int(Q.size()));
	}

	cout << Max;
}