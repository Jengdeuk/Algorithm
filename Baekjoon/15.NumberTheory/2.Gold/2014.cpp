#include <iostream>
#include <queue>
#include <climits>
using namespace std;

priority_queue<int, vector<int>, greater<int>> PQ;

int N, K;
int S[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
		PQ.emplace(S[i]);
	}

	int Cnt = 0, Num = 0, Pre = 0;
	while (Cnt++ < K)
	{
		while (PQ.top() == Pre)
		{
			PQ.pop();
		}

		Num = PQ.top();
		PQ.pop();

		for (int i = 0; i < N; ++i)
		{
			long long New = (long long)Num * S[i];
			if (New >= INT_MAX)
			{
				break;
			}

			PQ.emplace(New);

			if (Num % S[i] == 0)
			{
				break;
			}
		}

		Pre = Num;
	}

	cout << Pre;
}