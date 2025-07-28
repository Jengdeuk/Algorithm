#include <iostream>
#include <string>
using namespace std;

void Test()
{
	string S;
	cin >> S;

	int FalseCnt = 0, L = 0, R = S.size() - 1;
	while (L < R)
	{
		if (S[L] != S[R])
		{
			if (FalseCnt == 0)
			{
				FalseCnt++;

				int Cnt = 2;

				int LL = L + 1, RR = R;
				while (LL < RR)
				{
					if (S[LL] != S[RR])
					{
						Cnt--;
						break;
					}

					LL++;
					RR--;
				}

				LL = L, RR = R - 1;
				while (LL < RR)
				{
					if (S[LL] != S[RR])
					{
						Cnt--;
						break;
					}

					LL++;
					RR--;
				}

				if (Cnt > 0)
				{
					break;
				}
			}

			cout << "2\n";
			return;
		}
		else
		{
			L++;
			R--;
		}
	}

	if (FalseCnt == 0)
	{
		cout << "0\n";
	}
	else
	{
		cout << "1\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	int T;
	cin >> T;
	while (T--) Test();
}