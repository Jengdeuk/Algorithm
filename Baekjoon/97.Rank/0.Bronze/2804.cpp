#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string A, B;
	cin >> A >> B;

	int AN, BN;
	AN = A.size();
	BN = B.size();

	int AI = 0, BI = 0;
	for (int i = 0; i < AN; ++i)
	{
		for (int j = 0; j < BN; ++j)
		{
			if (A[i] == B[j])
			{
				AI = i;
				BI = j;
				i = AN, j = BN;
				break;
			}
		}
	}

	for (int i = 0; i < BN; ++i)
	{
		for (int j = 0; j < AN; ++j)
		{
			if (j == AI)
			{
				cout << B[i];
			}
			else if (i == BI)
			{
				cout << A[j];
			}
			else
			{
				cout << '.';
			}
		}

		cout << '\n';
	}
}