#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Height[9];
vector<int> Ordered;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 9; ++i)
	{
		cin >> Height[i];
	}

	int A, B;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = i + 1; j < 9; ++j)
		{
			int Sum = 0;
			for (int k = 0; k < 9; ++k)
			{
				if (k == i || k == j)
				{
					continue;
				}

				Sum += Height[k];
			}

			if (Sum == 100)
			{
				A = i;
				B = j;
				i = 9;
				break;
			}
		}
	}

	Ordered.reserve(7);
	for (int i = 0; i < 9; ++i)
	{
		if (i == A || i == B)
		{
			continue;
		}

		Ordered.emplace_back(Height[i]);
	}

	sort(Ordered.begin(), Ordered.end());

	for (const int& H : Ordered)
	{
		cout << H << '\n';
	}
}