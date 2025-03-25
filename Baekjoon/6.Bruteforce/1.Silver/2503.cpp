#include <iostream>
#include <string>
using namespace std;

struct query
{
	string num;
	int strike;
	int ball;
};

int n;
query q[100];

int cnt, cur[3];
bool v[10];

bool isCorrect()
{
	for (int k = 0; k < n; ++k)
	{
		int strike = 0;
		int ball = 0;
		for (int i = 0; i < 3; ++i)
		{
			if (cur[i] == q[k].num[i] - '0')
			{
				strike++;
				continue;
			}

			for (int j = 0; j < 3; ++j)
			{
				if (cur[i] == q[k].num[j] - '0')
				{
					ball++;
					break;
				}
			}
		}

		if (strike != q[k].strike || ball != q[k].ball)
			return false;
	}

	return true;
}

void func(int idx)
{
	if (idx == 3)
	{
		cnt += isCorrect();
		return;
	}

	for (int i = 1; i < 10; ++i)
	{
		if (v[i])
			continue;

		cur[idx] = i;
		v[i] = true;
		func(idx + 1);
		v[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> q[i].num >> q[i].strike >> q[i].ball;

	func(0);

	cout << cnt;
}