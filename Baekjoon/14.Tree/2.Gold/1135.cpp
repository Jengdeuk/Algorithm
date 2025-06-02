#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N;
vector<p> F[50];

int Count(int Cur)
{
	if (F[Cur].empty())
	{
		return 0;
	}

	for (p& f : F[Cur])
	{
		f.first = 1 + Count(f.second);
	}

	sort(F[Cur].begin(), F[Cur].end(), greater<>());

	vector<int> V;
	int Time = 0;
	for (const p f : F[Cur])
	{
		V.emplace_back(f.first + (Time++));
	}

	return *max_element(V.begin(), V.end());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Parent;
		cin >> Parent;
		if (Parent == -1)
		{
			continue;
		}

		F[Parent].emplace_back(0, i);
	}

	cout << Count(0);
}