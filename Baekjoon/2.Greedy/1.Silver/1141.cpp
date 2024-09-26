#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string S[50];
bool C[50];

bool Compare(string& L, string& R)
{
	return (L.size() == R.size() ? L < R : L.size() < R.size());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	sort(S, S + N, Compare);

	for (int i = 0; i < N; ++i)
	{
		bool bFound = false;
		int FI = i;
		for (int j = i - 1; j >= 0; --j)
		{
			if (C[j] == false)
			{
				continue;
			}

			bool bSame = true;
			for (int k = 0; k < S[j].size(); ++k)
			{
				if (S[j][k] != S[i][k])
				{
					bSame = false;
					break;
				}
			}

			if (bSame)
			{
				bFound = true;
				FI = j;
				break;
			}
		}

		C[i] = true;
		if (bFound)
		{
			C[FI] = false;
		}
	}

	int Count = 0;
	for (int i = 0; i < N; ++i)
	{
		Count += (C[i]);
	}

	cout << Count;
}