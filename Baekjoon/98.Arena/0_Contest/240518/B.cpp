#include <iostream>
#include <list>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K;
priority_queue<int> PQ;
list<int> S;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		int D;
		cin >> D;
		PQ.emplace(D);
	}

	int Y = 0;
	while (!PQ.empty())
	{
		int ND = PQ.top();
		PQ.pop();

		if (ND <= K)
		{
			continue;
		}

		int NS = Y / 2 + ND;
		ND -= M;
		Y = NS;
		S.emplace_back(NS);

		if (ND > K)
		{
			PQ.emplace(ND);
		}
	}

	cout << S.size() << '\n';
	for (const int& E : S)
	{
		cout << E << '\n';
	}
}