#include <iostream>
#include <algorithm>
using namespace std;

int Bot[100000], Top[100000], Cnt[500001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, H;
	cin >> N >> H;
	for (int i = 0; i < N / 2; ++i)
	{
		int B, T;
		cin >> B >> T;
		Bot[i] = B;
		Top[i] = H - T;
	}

	sort(Bot, Bot + N / 2);
	sort(Top, Top + N / 2);

	for (int i = 1; i <= H; ++i)
	{
		Cnt[i] += N / 2 - (lower_bound(Bot, Bot + N / 2, i) - Bot);
		Cnt[i] += (lower_bound(Top, Top + N / 2, i) - Top);
	}

	sort(Cnt + 1, Cnt + 1 + H);

	int Num = 0;
	for (int i = 1; i <= H; ++i)
	{
		if (Cnt[i] == Cnt[1])
		{
			++Num;
		}
		else
		{
			break;
		}
	}

	cout << Cnt[1] << ' ' << Num;
}