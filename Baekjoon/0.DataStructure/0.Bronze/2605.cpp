#include <iostream>
#include <list>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	list<int> L;
	for (int i = 1; i <= N; ++i)
	{
		int Idx;
		cin >> Idx;

		list<int>::iterator Iter = L.begin();
		for (int j = 0; j < Idx; ++j)
		{
			++Iter;
		}

		L.insert(Iter, i);
	}

	list<int>::iterator Iter = L.end();
	--Iter;

	for (int i = 0; i < L.size(); ++i)
	{
		cout << *Iter << ' ';
		if (Iter != L.begin())
		{
			--Iter;
		}
	}
}