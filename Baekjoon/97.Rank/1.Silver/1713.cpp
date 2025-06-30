#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

struct Info
{
	int Count;
	int Time;
};

typedef pair<int, Info> p;

int N;
map<int, Info> M;

bool Compare(const p& L, const p& R)
{
	return (L.second.Count == R.second.Count ? L.second.Time < R.second.Time : L.second.Count < R.second.Count);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		int Num;
		cin >> Num;
		if (M.count(Num))
		{
			M[Num].Count++;
			continue;
		}

		if (M.size() == N)
		{
			p Arr[20] = {};

			int Idx = 0;
			for (const p& Elem : M)
			{
				Arr[Idx++] = Elem;
			}

			M.erase((*min_element(Arr, Arr + N, Compare)).first);
		}

		M[Num].Count++;
		M[Num].Time = i;
	}

	for (const pair<int, Info>& Elem : M)
	{
		cout << Elem.first << ' ';
	}
}