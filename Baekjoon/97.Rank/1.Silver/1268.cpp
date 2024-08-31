#include <iostream>
#include <algorithm>
using namespace std;

int N;
int Student[1001][6];
int Count[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= 5; ++j)
		{
			int C;
			cin >> C;
			Student[i][j] = C;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		int Cnt = 0;
		for (int j = 1; j <= N; ++j)
		{
			if (i == j)
			{
				continue;
			}

			for (int k = 1; k <= 5; ++k)
			{
				if (Student[i][k] == Student[j][k])
				{
					++Cnt;
					break;
				}
			}
		}

		Count[i] = Cnt;
	}

	if (*max_element(Count, Count + N) > 0)
	{
		cout << max_element(Count, Count + N) - Count;
	}
	else
	{
		cout << 1;
	}
}