#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

void TestCase()
{
	int N, M;
	cin >> N >> M;

	deque<pair<int, int>> PrinterQueue;
	for (int i = 0; i < N; ++i)
	{
		int Priority;
		cin >> Priority;
		PrinterQueue.emplace_back(Priority, i);
	}
	
	int Cnt = 1;
	while (!PrinterQueue.empty())
	{
		int Priority = PrinterQueue.front().first;
		int Order = PrinterQueue.front().second;

		if (Priority == (*max_element(PrinterQueue.begin(), PrinterQueue.end())).first)
		{
			PrinterQueue.pop_front();

			if (Order == M)
			{
				break;
			}

			++Cnt;
		}
		else
		{
			PrinterQueue.pop_front();
			PrinterQueue.emplace_back(Priority, Order);
		}
	}

	cout << Cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int TC;
	cin >> TC;
	for (int i = 0; i < TC; ++i)
	{
		TestCase();
	}
}