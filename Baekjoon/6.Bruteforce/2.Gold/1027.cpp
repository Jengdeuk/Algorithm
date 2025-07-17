#include <iostream>
using namespace std;

int N, H[50];
bool S[50][50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> H[i];
	}

	for (int i = 0; i < N; ++i)
	{
		double MInc = -1234567890;
		for (int j = i + 1; j < N; ++j)
		{
			double Inc = double(H[j] - H[i]) / (j - i);
			if (Inc > MInc)
			{
				S[i][j] = true;
				S[j][i] = true;
				MInc = Inc;
			}
		}
	}

	int MCnt = 0;
	for (int i = 0; i < N; ++i)
	{
		int Cnt = 0;
		for (int j = 0; j < N; ++j)
		{
			if (j == i)
			{
				continue;
			}

			Cnt += S[i][j];
		}

		MCnt = max(MCnt, Cnt);
	}

	cout << MCnt;
}