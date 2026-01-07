#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> GetPi(string p)
{
	int m = p.size();
	vector<int> pi(m, 0);

	int j = 0;
	for (int i = 1; i < m; ++i)
	{
		while (j > 0 && p[i] != p[j])
		{
			j = pi[j - 1];
		}

		if (p[i] == p[j])
		{
			pi[i] = ++j;
		}
	}

	return pi;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string t, p;

	getline(cin, t);
	getline(cin, p);

	int n = t.size();
	int m = p.size();

	vector<int> pi(GetPi(p));

	vector<int> iv;
	
	int j = 0;
	for (int i = 0; i < n; ++i)
	{
		while (j > 0 && t[i] != p[j])
		{
			j = pi[j - 1];
		}

		if (t[i] == p[j])
		{
			j++;
			if (j == m)
			{
				iv.emplace_back(i - (m - 1));
				j = pi[j - 1];
			}
		}
	}

	cout << iv.size() << '\n';
	for (int idx : iv)
	{
		cout << idx + 1 << ' ';
	}
}