#include <iostream>
#include <vector>
using namespace std;

int Shop[100][2];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	int ShopSize = 0;
	for (int i = 0; i < N; ++i)
	{
		int Cost, Get;
		cin >> Cost >> Get;
		if (Get >= Cost)
		{
			Shop[ShopSize][0] = Cost;
			Shop[ShopSize][1] = Get;
			++ShopSize;
		}
	}

	int Carrot = 0;
	int S = 1;
	for (int i = 1; i < K; ++i)
	{
		bool bBought = false;

		int MaxIndex = -1;
		int MaxCarrot = 0;
		for (int j = 0; j < ShopSize; ++j)
		{
			if (Carrot < Shop[j][0])
			{
				continue;
			}

			int Cost = Shop[j][0];
			int NewS = S + Shop[j][1];

			int OriginCarrot = S * (K - i + 1);
			int NewCarrot = NewS * (K - i) - Cost;
			if (NewCarrot >= OriginCarrot
				&& NewCarrot > MaxCarrot)
			{
				MaxIndex = j;
				MaxCarrot = NewCarrot;
			}
		}

		if (MaxIndex != -1)
		{
			Carrot -= Shop[MaxIndex][0];
			S += Shop[MaxIndex][1];
			bBought = true;
		}

		if (!bBought)
		{
			Carrot += S;
		}
	}

	Carrot += S;
	cout << Carrot;
}