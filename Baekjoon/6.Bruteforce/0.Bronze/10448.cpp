#include <iostream>
using namespace std;

void Test()
{
	int K;
	cin >> K;

	bool bFound = false;
	for (int i = 1; i <= 45; ++i)
	{
		for (int j = 1; j <= 45; ++j)
		{
			for (int k = 1; k <= 45; ++k)
			{
				int Sum = (i * (i + 1) / 2) + (j * (j + 1) / 2) + (k * (k + 1) / 2);
				if (Sum > K)
				{
					break;
				}

				if (Sum == K)
				{
					bFound = true;
					i = 46, j = 46, k = 46;
					break;
				}
			}
		}
	}

	cout << bFound << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}