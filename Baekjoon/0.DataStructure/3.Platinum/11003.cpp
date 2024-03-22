#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int Seq[5000000];
priority_queue<p, vector<p>, greater<p>> PQ;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, L;
	cin >> N >> L;
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;
		Seq[i] = Num;
		PQ.emplace(Num, i);

		while (i - PQ.top().second >= L)
		{
			PQ.pop();
		}

		cout << PQ.top().first << ' ';
	}
}