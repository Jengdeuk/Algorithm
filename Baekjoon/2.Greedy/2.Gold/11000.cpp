#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N, Room;
p Class[200000];
priority_queue<int, vector<int>, greater<int>> CQ;

void AddRoom(int T)
{
	CQ.emplace(T);
	Room = max(Room, (int)CQ.size());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Class[i].first >> Class[i].second;
	}

	sort(Class, Class + N);

	for (int i = 0; i < N; ++i)
	{
		int S = Class[i].first;
		int T = Class[i].second;

		if (CQ.empty())
		{
			AddRoom(T);
			continue;
		}

		if (CQ.top() <= S)
		{
			CQ.pop();
			CQ.emplace(T);
		}
		else
		{
			AddRoom(T);
		}
	}

	cout << Room;
}