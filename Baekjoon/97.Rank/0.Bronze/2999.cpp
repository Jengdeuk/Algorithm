#include <iostream>
#include <string>
using namespace std;

int N, M;
char Mat[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;

	int Size = S.size();
	for (int i = 1; i <= Size; ++i)
	{
		for (int j = i; j <= Size; ++j)
		{
			if (i * j == Size)
			{
				N = i;
				M = j;
			}
		}
	}

	int R = 0, C = 0;
	for (const char ch : S)
	{
		Mat[R][C] = ch;
		if (++R == N)
		{
			R = 0;
			++C;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << Mat[i][j];
		}
	}
}