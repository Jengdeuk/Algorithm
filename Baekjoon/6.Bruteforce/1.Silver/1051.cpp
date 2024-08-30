#include <iostream>
#include <string>
using namespace std;

int N, M;
int Map[50][50];

bool IsValid(int R, int C, int Size)
{
	if (Map[R][C] != Map[R + Size - 1][C]
		|| Map[R][C] != Map[R][C + Size - 1]
		|| Map[R][C] != Map[R + Size - 1][C + Size - 1])
	{
		return false;
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;

		for (int j = 0; j < M; ++j)
		{
			Map[i][j] = S[j] - '0';
		}
	}

	int Size = min(N, M);
	while (Size > 1)
	{
		bool bFound = false;
		for (int i = 0; i + Size <= N; ++i)
		{
			for (int j = 0; j + Size <= M; ++j)
			{
				if (IsValid(i, j, Size))
				{
					bFound = true;
					i = N;
					j = M;
				}
			}
		}

		if (bFound)
		{
			break;
		}

		--Size;
	}

	cout << Size * Size;
}