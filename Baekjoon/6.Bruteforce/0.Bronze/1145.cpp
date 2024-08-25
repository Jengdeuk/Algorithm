#include <iostream>
#include <algorithm>
using namespace std;

const int Size = 5;
int S[Size];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < Size; ++i)
	{
		cin >> S[i];
	}

	sort(S, S + Size);

	int N = 3;
	while (true)
	{
		int Cnt = 0;
		for (int i = 0; i < Size; ++i)
		{
			if (N % S[i] == 0)
			{
				++Cnt;
			}
		}

		if (Cnt >= 3)
		{
			break;
		}

		++N;
	}

	cout << N;
}