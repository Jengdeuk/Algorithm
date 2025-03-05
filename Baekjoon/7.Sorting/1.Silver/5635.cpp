#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct info
{
	string name;
	int year;
	int month;
	int date;
};

int n;
info st[100];

bool compare(const info& l, const info& r)
{
	return (l.year == r.year ? (l.month == r.month ? l.date < r.date : l.month < r.month) : l.year < r.year);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> st[i].name >> st[i].date >> st[i].month >> st[i].year;

	sort(st, st + n, compare);

	cout << st[n - 1].name << '\n' << st[0].name;
}