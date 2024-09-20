#include <iostream>
using namespace std;

const int Size = 100000;

bool P[Size + 1];
int C[Size + 1];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, B;
	cin >> A >> B;

	for (int i = 2; i <= Size; ++i)
	{
		P[i] = true;
	}

	for (int i = 2; i <= Size / 2; ++i)
	{
		if (!P[i])
		{
			continue;
		}

		for (int j = 2; i * j <= Size; ++j)
		{
			P[i * j] = false;
		}
	}

	for (int i = 2; i <= Size; ++i)
	{
		if (P[i])
		{
			C[i] = 1;
		}
		else
		{
			for (int j = 2; j < i; ++j)
			{
				if (P[j] && i % j == 0)
				{
					C[i] = C[i / j] + 1;
					break;
				}
			}
		}
	}

	int Cnt = 0;
	for (int i = A; i <= B; ++i)
	{
		if (P[C[i]])
		{
			++Cnt;
		}
	}

	cout << Cnt;
}