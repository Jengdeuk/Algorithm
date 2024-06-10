#include <iostream>
#include <string>
#include <cmath>
using namespace std;

typedef long long ll;

int N;
int Map[30][30];
string DP[30][30];

string MaxString(int R, int C)
{
	string Up = DP[R - 1][C], Left = DP[R][C - 1];
	for (int i = 0; i < Up.size(); ++i)
	{
		if (Up[i] - '0' > Left[i] - '0')
		{
			return Up;
		}

		if (Left[i] - '0' > Up[i] - '0')
		{
			return Left;
		}
	}

	return Up;
}

ll GetNum(string S)
{
	ll Num = 0;

	int Size = S.size() - 1;
	for (int i = Size; i >= 0; --i)
	{
		Num += (S[i] - '0') * ll(pow(ll(2), ll(Size - i)));
	}

	return Num;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> Map[i][j];
		}
	}

	DP[0][0] += Map[0][0] + '0';
	for (int i = 1; i < N; ++i)
	{
		DP[0][i] = DP[0][i - 1];
		DP[0][i] += Map[0][i] + '0';

		DP[i][0] = DP[i - 1][0];
		DP[i][0] += Map[i][0] + '0';
	}

	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < N; ++j)
		{
			DP[i][j] = MaxString(i, j);
			DP[i][j] += Map[i][j] + '0';
		}
	}

	cout << GetNum(DP[N - 1][N - 1]);
}