#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> OrderedList(N);
	for (int i = 0; i < N; ++i)
	{
		cin >> OrderedList[i];
	}

	sort(OrderedList.begin(), OrderedList.end());

	for (const int& Number : OrderedList)
	{
		cout << Number << '\n';
	}
}