#include <iostream>
#include <string>
using namespace std;

int N, M;
char Map[50][50];
bool Row[50], Col[50];

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
			Map[i][j] = S[j];

			if (S[j] == 'X')
			{
				Row[i] = true;
				Col[j] = true;
			}
		}
	}

	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		if (Row[i])
		{
			continue;
		}

		for (int j = 0; j < M; ++j)
		{
			if (Col[j])
			{
				continue;
			}

			Col[j] = true;
			break;
		}

		Row[i] = true;
		++Cnt;
	}

	for (int i = 0; i < M; ++i)
	{
		if (Col[i])
		{
			continue;
		}

		for (int j = 0; j < N; ++j)
		{
			if (Row[j])
			{
				continue;
			}

			Row[j] = true;
			break;
		}

		Col[i] = true;
		++Cnt;
	}

	cout << Cnt;
}