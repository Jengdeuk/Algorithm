#include <iostream>
#include <deque>
using namespace std;

typedef pair<int, int> p;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	deque<p> Q;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;
		Q.emplace_back(i + 1, Num);
	}

	while (!Q.empty())
	{
		int Idx = Q.front().first;
		int Num = Q.front().second;
		Q.pop_front();

		cout << Idx << ' ';

		if (Q.empty())
		{
			break;
		}
		else if (Num > 0)
		{
			--Num;
			while (Num != 0)
			{
				Q.emplace_back(Q.front());
				Q.pop_front();
				--Num;
			}
		}
		else
		{
			while (Num != 0)
			{
				Q.emplace_front(Q.back());
				Q.pop_back();
				++Num;
			}
		}
	}
}