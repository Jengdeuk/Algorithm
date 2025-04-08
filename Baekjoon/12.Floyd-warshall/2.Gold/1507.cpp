#include <iostream>
#include <cstring>
using namespace std;

int n, org[20][20], cpy[20][20];
bool c[20][20];

void fw()
{
	memset(c, true, sizeof(c));
	memcpy(cpy, org, sizeof(cpy));

	for (int k = 0; k < n; ++k)
	{
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (k == i || k == j || i == j)
					continue;

				int nv = cpy[i][k] + cpy[k][j];
				if (nv <= cpy[i][j])
				{
					c[i][j] = false;
					cpy[i][j] = nv;
				}
			}
		}
	}
}

bool isCorrect()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (org[i][j] != cpy[i][j])
				return false;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> org[i][j];

	fw();

	int sum = 0;
	if (isCorrect())
	{
		for (int i = 0; i < n; ++i)
			for (int j = i + 1; j < n; ++j)
				if (c[i][j])
					sum += org[i][j];
	}
	else
	{
		sum = -1;
	}

	cout << sum;
}