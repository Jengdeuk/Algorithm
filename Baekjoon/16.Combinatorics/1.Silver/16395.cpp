#include <iostream>
using namespace std;

int C[31][31];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 1; i <= 30; ++i)
	{
		C[i][1] = 1;
	}

	for (int j = 2; j <= 30; ++j)
	{
		C[j][j] = 1;
	}

	for (int i = 3; i <= 30; ++i)
	{
		for (int j = 2; j < i; ++j)
		{
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}

	int N, K;
	cin >> N >> K;
	cout << C[N][K];
}