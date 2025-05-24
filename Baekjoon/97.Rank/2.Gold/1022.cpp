#include <iostream>
#include <string>
using namespace std;

int minColNum[5001], plsColNum[5001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int cur = 1;
	plsColNum[0] = 1;
	for (int i = 1; i <= 5000; ++i)
	{
		plsColNum[i] = plsColNum[i - 1] + cur;
		cur += 8;
	}

	cur = 5;
	minColNum[0] = 1;
	for (int i = 1; i <= 5000; ++i)
	{
		minColNum[i] = minColNum[i - 1] + cur;
		cur += 8;
	}

	int r1, c1, r2, c2;
	cin >> r1 >> c1 >> r2 >> c2;

	int big = 0;

	string sb = to_string(big);
	int l = sb.size();
	for (int i = r1; i <= r2; ++i)
	{
		for (int j = c1; j <= c2; ++j)
		{
			int num = 0;
			if (j < 0)
			{
				num = minColNum[abs(j)] + i;
			}
			else
			{
				num = plsColNum[j] - i;
			}
			cout.width(l);
			cout << std::right << num << ' ';
		}
		cout << '\n';
	}
}