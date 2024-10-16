#include <iostream>
#include <string>
using namespace std;

int N, K;
string S;
char M[200][20];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> K >> S;
	N = S.size() / K;

	int Idx = 0;
	for (int i = 0; i < N; ++i)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < K; ++j)
			{
				M[i][j] = S[Idx++];
			}
		}
		else
		{
			for (int j = K - 1; j >= 0; --j)
			{
				M[i][j] = S[Idx++];
			}
		}
	}

	string Answer;
	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			Answer.push_back(M[j][i]);
		}
	}

	cout << Answer;
}