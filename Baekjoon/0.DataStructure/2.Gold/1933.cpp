#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

typedef pair<int, int> p;
typedef pair<p, bool> pb;

int N;
pb Event[200000];

bool Compare(const pb& L, const pb& R)
{
	if (L.first.first < R.first.first)
	{
		return true;
	}
	else if (L.first.first > R.first.first)
	{
		return false;
	}

	if (L.second && R.second == false)
	{
		return true;
	}
	else if (L.second == false && R.second)
	{
		return false;
	}

	if (L.second && R.second)
	{
		return (L.first.second >= R.first.second);
	}
	else
	{
		return (L.first.second <= R.first.second);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < 2 * N; i += 2)
	{
		int S, H, E;
		cin >> S >> H >> E;
		Event[i] = pb(p(S, H), true);
		Event[i + 1] = pb(p(E, H), false);
	}

	sort(Event, Event + 2 * N, Compare);

	map<int, int> M;
	for (int i = 0; i < 2 * N; ++i)
	{
		bool bStartEvent = Event[i].second;
		int X = Event[i].first.first;
		int H = Event[i].first.second;
		if (bStartEvent)
		{
			if (M.empty() || H > (--M.end())->first)
			{
				cout << X << ' ' << H << ' ';
			}

			M[H]++;
		}
		else
		{
			if (--M[H] == 0)
			{
				M.erase(H);
			}

			if (M.empty())
			{
				cout << X << ' ' << 0 << ' ';
			}
			else if (H > (--M.end())->first)
			{
				cout << X << ' ' << (--M.end())->first << ' ';
			}
		}
	}
}