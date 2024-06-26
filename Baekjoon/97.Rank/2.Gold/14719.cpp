#include <iostream>
using namespace std;

int N, M;
int Map[500][500];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int j = 0; j < M; ++j)
	{
		int H;
		cin >> H;
		for (int i = 0; i < H; ++i)
		{
			Map[i][j] = 1;
		}
	}

	int Water = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!Map[i][j])
			{
				continue;
			}

			int L = j, R = j + 1;
			for (int k = R; k < M; ++k)
			{
				if (Map[i][k])
				{
					R = k;
					break;
				}
			}

			if (R - L - 1 > 0)
			{
				Water += R - L - 1;
			}

			j = R - 1;
		}
	}

	cout << Water;
}