#include <iostream>
using namespace std;

void Test()
{
	int TN;
	cin >> TN;

	int Idx = 0;
	int L[20] = {};

	int Cnt = 0;
	for (int i = 0; i < 20; ++i)
	{
		int Hight;
		cin >> Hight;

		int Idx = i;
		for (int j = 0; j < i; ++j)
		{
			if (L[j] > Hight)
			{
				Idx = j;
				break;
			}
		}

		for (int j = i - 1; j >= Idx; --j)
		{
			L[j + 1] = L[j];
			Cnt++;
		}

		L[Idx] = Hight;
	}

	cout << TN << ' ' << Cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) Test();
}