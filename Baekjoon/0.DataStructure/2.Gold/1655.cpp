#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> LQ;
priority_queue<int, vector<int>, greater<int>> RQ;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;

		if (LQ.empty())
		{
			LQ.emplace(Num);
		}
		else if (LQ.size() == RQ.size())
		{
			if (Num < RQ.top())
			{
				LQ.emplace(Num);
			}
			else
			{
				LQ.emplace(RQ.top());
				RQ.pop();
				RQ.emplace(Num);
			}
		}
		else
		{
			if (Num >= LQ.top())
			{
				RQ.emplace(Num);
			}
			else
			{
				RQ.emplace(LQ.top());
				LQ.pop();
				LQ.emplace(Num);
			}
		}

		cout << LQ.top() << '\n';
	}
}