#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

unordered_set<int> HashTable;
vector<int> OrderedList;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int Number;
		cin >> Number;
		HashTable.emplace(Number);
	}

	OrderedList.reserve(HashTable.size());
	for (const int& Number : HashTable)
	{
		OrderedList.emplace_back(Number);
	}

	sort(OrderedList.begin(), OrderedList.end());

	for (const int& Number : OrderedList)
	{
		cout << Number << '\n';
	}
}