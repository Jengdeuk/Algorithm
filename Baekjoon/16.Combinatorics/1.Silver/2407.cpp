#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string C[101][101];

string Sum(string A, string B)
{
	string Ret;

	int AI = A.size() - 1;
	int BI = B.size() - 1;

	int Up = 0;
	while (AI >= 0 && BI >= 0)
	{
		int Sum = (A[AI--] - '0') + (B[BI--] - '0') + (Up == 1 ? 1 : 0);
		if (Sum >= 10)
		{
			Up = 1;
			Sum -= 10;
		}
		else
		{
			Up = 0;
		}

		Ret.push_back(Sum + '0');
	}

	if (AI < 0 && BI < 0 && Up == 1)
	{
		Ret.push_back('1');
		Up = 0;
	}

	while (AI >= 0)
	{
		int Sum = (A[AI--] - '0') + (Up == 1 ? 1 : 0);
		if (Sum >= 10)
		{
			Up = 1;
			Sum -= 10;
		}
		else
		{
			Up = 0;
		}

		Ret.push_back(Sum + '0');
	}

	while (BI >= 0)
	{
		int Sum = (B[BI--] - '0') + (Up == 1 ? 1 : 0);
		if (Sum >= 10)
		{
			Up = 1;
			Sum -= 10;
		}
		else
		{
			Up = 0;
		}

		Ret.push_back(Sum + '0');
	}

	if (AI < 0 && BI < 0 && Up == 1)
	{
		Ret.push_back('1');
		Up = 0;
	}

	reverse(Ret.begin(), Ret.end());

	return Ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 1; i <= 100; ++i)
	{
		C[i][0] = "1";
		C[i][i] = "1";
		for (int j = 1; j < i; ++j)
		{
			C[i][j] = Sum(C[i - 1][j], C[i - 1][j - 1]);
		}
	}

	int N, M;
	cin >> N >> M;
	cout << C[N][M];
}