#include <iostream>
#include <set>
#include <unordered_map>
using namespace std;

int X[1000000];
set<int> OrderedList;
unordered_map<int, int> Map;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> X[i];
		OrderedList.emplace(X[i]);
		Map.emplace(X[i], -1);
	}

	int i = 0;
	for (const int& Number : OrderedList)
	{
		Map[Number] = i;
		++i;
	}

	for (int i = 0; i < N; ++i)
	{
		cout << Map[X[i]] << ' ';
	}
}