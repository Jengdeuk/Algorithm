#include <iostream>
#include <string>
using namespace std;

bool Pal[2500][2500];
int DP[2500];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string Str;
	cin >> Str;

	int Size = Str.length();
	for (int d = 0; d < Size; ++d)
	{
		for (int i = 0; i + d < Size; ++i)
		{
			if (d == 0)
			{
				Pal[i][i + d] = true;
				continue;
			}

			if (Str[i] == Str[i + d]
				&& (d == 1 || Pal[i + 1][i + d - 1]))
			{
				Pal[i][i + d] = true;
			}
		}
	}

	for (int i = 0; i < Size; ++i)
	{
		DP[i] = 2500;
		for (int j = 0; j <= i; ++j)
		{
			if (Pal[j][i])
			{
				if (j == 0)
				{
					DP[i] = 1;
					break;
				}
				else
				{
					DP[i] = min(DP[i], DP[j - 1] + 1);
				}
			}
		}
	}

	cout << DP[Size - 1];
}