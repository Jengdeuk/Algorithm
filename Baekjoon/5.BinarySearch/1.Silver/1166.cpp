#include <iostream>
using namespace std;

typedef long long ll;

ll N, L, W, H;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> L >> W >> H;

	long double Max;
	long double S = 0;
	long double E = min(L, min(W, H));
	int Cnt = 0;
	while (S <= E)
	{
		if (Cnt == 200)
		{
			break;
		}

		long double M = (S + E) / 2;
		if (N <= ll(L / M) * ll(W / M) * ll(H / M))
		{
			Max = M;
			S = M;
		}
		else
		{
			E = M;
		}

		++Cnt;
	}

	cout.precision(30);
	cout << Max;
}