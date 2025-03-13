#include <iostream>
#include <string>
using namespace std;

int n;
bool row[20];

int minCnt = 400;

void btf(int idx, string s)
{
	if (idx == n)
	{
		int cnt = 0;
		for (int j = 0; j < n; ++j)
		{
			int hn = 0, tn = 0;
			for (int i = 0; i < n; ++i)
			{
				if (s[i * n + j] == 'H')
					hn++;
				else
					tn++;
			}

			if (tn > hn)
				cnt += hn;
			else
				cnt += tn;
		}

		minCnt = min(minCnt, cnt);
		return;
	}

	string ns = s;
	for (int j = 0; j < n; ++j)
	{
		int x = idx * n + j;
		if (ns[x] == 'H')
			ns[x] = 'T';
		else
			ns[x] = 'H';
	}

	row[idx] = true;
	btf(idx + 1, ns);

	row[idx] = false;
	btf(idx + 1, s);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> n;

	string s;
	for (int i = 0; i < n; ++i)
	{
		string ss;
		cin >> ss;
		s.append(ss);
	}

	btf(0, s);

	cout << minCnt;
}