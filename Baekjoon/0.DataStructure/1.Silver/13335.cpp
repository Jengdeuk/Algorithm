#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int w, sum, t;
queue<p> q;

void moveTrucks()
{
	queue<p> temp;
	while (q.empty() == false)
	{
		if (q.front().first + 1 == w + 1)
		{
			sum -= q.front().second;
			q.pop();
			continue;
		}

		temp.emplace(q.front().first + 1, q.front().second);
		q.pop();
	}

	q = temp;
	t++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, l;
	cin >> n >> w >> l;

	for (int i = 0; i < n; ++i)
	{
		int truck;
		cin >> truck;
		if (q.size() < w && sum + truck <= l)
		{
			moveTrucks();
			sum += truck;
			q.emplace(1, truck);
			continue;
		}

		while (q.size() == w || sum + truck > l)
			moveTrucks();

		sum += truck;
		q.emplace(1, truck);
	}

	while (q.empty() == false)
		moveTrucks();

	cout << t;
}