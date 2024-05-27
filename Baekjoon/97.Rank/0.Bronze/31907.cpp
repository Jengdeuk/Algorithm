#include <iostream>
using namespace std;

const int R = 3;
const int C = 4;

char GIST[R][C] =
{
	{ 'G', '.', '.', '.' },
	{ '.', 'I', '.', 'T' },
	{ '.', '.', 'S', '.' }
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int K;
	cin >> K;
	for (int r = 0; r < R; ++r)
	{
		for (int i = 0; i < K; ++i)
		{
			for (int c = 0; c < C; ++c)
			{
				for (int j = 0; j < K; ++j)
				{
					cout << GIST[r][c];
				}
			}

			cout << '\n';
		}
	}
}