#include <iostream>
using namespace std;

int N, HR, HC;
char Map[1000][1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;

	bool bFoundHead = false;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Map[i][j];
			if (!bFoundHead && Map[i][j] == '*')
			{
				bFoundHead = true;
				HR = i + 1, HC = j;
			}
		}
	}

	int LA = 0, RA = 0, W = 0, LL = 0, RL = 0;

	int R = HR, C = HC;
	while (--C >= 0 && Map[R][C] == '*')
	{
		++LA;
	}

	R = HR, C = HC;
	while (++C < N && Map[R][C] == '*')
	{
		++RA;
	}

	R = HR, C = HC;
	while (++R < N && Map[R][C] == '*')
	{
		++W;
	}

	int WR = R - 1, WC = C;
	R = WR, C = WC - 1;
	while (++R < N && Map[R][C] == '*')
	{
		++LL;
	}

	R = WR, C = WC + 1;
	while (++R < N && Map[R][C] == '*')
	{
		++RL;
	}
	
	cout << HR + 1 << ' ' << HC + 1 << '\n';
	cout << LA << ' ' << RA << ' ' << W << ' ' << LL << ' ' << RL;
}