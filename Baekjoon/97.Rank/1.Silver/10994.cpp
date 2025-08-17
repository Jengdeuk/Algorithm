#include <iostream>
using namespace std;

bool S[397][397];

void Draw(int N, int L, int R, int T, int B)
{
	if (N == 0)
	{
		return;
	}

	for (int i = L; i <= R; ++i)
	{
		S[T][i] = true;
		S[B][i] = true;
	}

	for (int i = T; i <= B; ++i)
	{
		S[i][L] = true;
		S[i][R] = true;
	}

	Draw(N - 1, L + 2, R - 2, T + 2, B - 2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	Draw(N, 0, (N - 1) * 4, 0, (N - 1) * 4);

	for (int i = 0; i < (N - 1) * 4 + 1; ++i)
	{
		for (int j = 0; j < (N - 1) * 4 + 1; ++j)
		{
			if (S[i][j])
			{
				cout << '*';
			}
			else
			{
				cout << ' ';
			}
		}
		cout << '\n';
	}
}