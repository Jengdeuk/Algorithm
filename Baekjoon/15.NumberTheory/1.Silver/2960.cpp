#include <iostream>
using namespace std;

int P[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	for (int i = 2; i <= N; ++i)
	{
		P[i] = true;
	}

	int Cnt = 0, Num = 0;
	for (int i = 2; i <= N; ++i)
	{
		if (!P[i])
		{
			continue;
		}

		++Cnt;
		if (Cnt == K)
		{
			Num = i;
			break;
		}

		for (int j = 2; j * i <= N; ++j)
		{
			if (!P[j * i])
			{
				continue;
			}

			++Cnt;
			if (Cnt == K)
			{
				Num = j * i;
				i = N;
				break;
			}

			P[j * i] = false;
		}
	}

	cout << Num;
}