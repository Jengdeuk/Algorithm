#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

typedef tuple<int, int, string> Tuple;

vector<Tuple> UserInfoTable;

bool Compare(const Tuple& Left, const Tuple& Right)
{
	return (get<1>(Left) == get<1>(Right)) ? get<0>(Left) < get<0>(Right) : get<1>(Left) < get<1>(Right);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Age;
		string Name;
		cin >> Age >> Name;
		UserInfoTable.emplace_back(i, Age, Name);
	}

	sort(UserInfoTable.begin(), UserInfoTable.end(), Compare);

	for (const Tuple& User : UserInfoTable)
	{
		cout << get<1>(User) << ' ' << get<2>(User) << '\n';
	}
}