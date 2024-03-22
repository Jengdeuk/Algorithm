#include <iostream>
using namespace std;

long long Factory[1000002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	long long N, B, C;
	cin >> N >> B >> C;
	for (int i = 0; i < N; ++i)
	{
		cin >> Factory[i];
	}

	long long Price = 0;
	if (B < C)
	{
		for (int i = 0; i < N; ++i)
		{
			Price += Factory[i] * B;
		}

		cout << Price;
		return 0;
	}

	for (int i = 0; i < N; ++i)
	{
		int Num;
		if (Factory[i + 1] > Factory[i + 2])
		{
			Num = min(Factory[i], Factory[i + 1] - Factory[i + 2]);
			Price += Num * (B + C);
			Factory[i] -= Num;
			Factory[i + 1] -= Num;
		}

		Num = min(Factory[i], min(Factory[i + 1], Factory[i + 2]));
		Price += Num * (B + 2 * C);
		Factory[i] -= Num;
		Factory[i + 1] -= Num;
		Factory[i + 2] -= Num;

		Price += Factory[i] * B;
	}

	cout << Price;
}