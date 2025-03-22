#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int getSum(const string& s)
{
	int sum = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] <= '9')
			sum += s[i] - '0';

	return sum;
}

bool compare(const string& l, const string& r)
{
	int ls = getSum(l);
	int rs = getSum(r);
	return l.size() == r.size() ? (ls == rs ? l < r : ls < rs) : l.size() < r.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	string ns[50];
	for (int i = 0; i < n; ++i)
		cin >> ns[i];

	sort(ns, ns + n, compare);

	for (int i = 0; i < n; ++i)
		cout << ns[i] << '\n';
}