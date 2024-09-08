#include <iostream>
#include <string>
using namespace std;

int N, M;
bool A[50][50], B[50][50];

bool IsSame()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (A[i][j] != B[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

void TurnElements(int R, int C)
{
	for (int i = R; i < R + 3; ++i)
	{
		for (int j = C; j < C + 3; ++j)
		{
			A[i][j] = !A[i][j];
		}
	}
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
			A[i][j] = S[j] - '0';
		}
	}

	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		for (int j = 0; j < M; ++j)
		{
			B[i][j] = S[j] - '0';
		}
	}

	bool bFound = false;
	if (IsSame())
	{
		bFound = true;
	}

	int Count = 0;
	for (int i = 0; i < N - 2; ++i)
	{
		for (int j = 0; j < M - 2; ++j)
		{
			if (A[i][j] == B[i][j])
			{
				continue;
			}

			TurnElements(i, j);
			++Count;

			if (IsSame())
			{
				bFound = true;
				i = N;
				j = M;
				break;
			}
		}
	}

	if (bFound)
	{
		cout << Count;
	}
	else
	{
		cout << -1;
	}
}