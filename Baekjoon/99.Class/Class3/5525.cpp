#include <iostream>
#include <string>
using namespace std;

string S;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M >> S;

	int Count = 0;
	for (int i = 0; i < M; ++i)
	{
		int K = 0;

		if (S[i] == 'O')
		{
			continue;
		}

		while (S[i + 1] == 'O' && S[i + 2] == 'I')
		{
			++K;

			if (K == N)
			{
				--K;
				++Count;
			}

			i += 2;
		}
	}

	cout << Count;
}