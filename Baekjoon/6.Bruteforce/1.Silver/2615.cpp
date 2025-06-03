#include <iostream>
using namespace std;

const int N = 19;

const int DX[4] = { 1, 0, 1, 1 };
const int DY[4] = { 0, 1, 1, -1 };

int M[N][N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> M[i][j];
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (M[i][j] == 0)
			{
				continue;
			}

			for (int d = 0; d < 4; ++d)
			{
				int Cnt = 0;
				for (int k = 1; k < 5; ++k)
				{
					int R = i + k * DY[d];
					int C = j + k * DX[d];
					if (R < 0 || R > N - 1 || C < 0 || C > N - 1 || M[R][C] != M[i][j])
					{
						break;
					}

					Cnt++;
				}

				if (Cnt == 4)
				{
					int PR = i - 1 * DY[d];
					int PC = j - 1 * DX[d];
					int NR = i + 5 * DY[d];
					int NC = j + 5 * DX[d];
					if (((PR >= 0 && PR < N && PC >= 0 && PC < N && M[PR][PC] != M[i][j]) || (PR < 0 || PR > N - 1 || PC < 0 || PC > N - 1))
						&& ((NR >= 0 && NR < N && NC >= 0 && NC < N && M[NR][NC] != M[i][j]) || (NR < 0 || NR > N - 1 || NC < 0 || NC > N - 1)))
					{
						cout << M[i][j] << '\n';
						cout << i + 1 << ' ' << j + 1;
						return 0;
					}
				}
			}
		}
	}

	cout << 0;
}