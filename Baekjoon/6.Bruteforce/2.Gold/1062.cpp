#include <iostream>
#include <string>
using namespace std;

int N, K, MCnt;
string S[50];
bool A[26];

int Count()
{
	int Cnt = 0;
	for (int i = 0; i < 26; ++i)
	{
		Cnt += A[i];
	}

	return Cnt;
}

void BF(int Alpha)
{
	if (Alpha == 26)
	{
		if (Count() == K)
		{
			int Cnt = 0;
			for (int i = 0; i < N; ++i)
			{
				bool IsReadable = true;
				for (const char Ch : S[i])
				{
					if (A[Ch - 'a'] == false)
					{
						IsReadable = false;
						break;
					}
				}

				Cnt += IsReadable;
			}

			MCnt = max(MCnt, Cnt);
		}

		return;
	}

	switch (Alpha)
	{
	case 'a' - 'a':
	case 'n' - 'a':
	case 't' - 'a':
	case 'i' - 'a':
	case 'c' - 'a':
		BF(Alpha + 1);
		break;
	default:
		A[Alpha] = true;
		BF(Alpha + 1);
		A[Alpha] = false;
		BF(Alpha + 1);
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	if (K < 5)
	{
		cout << 0;
		return 0;
	}

	A['a' - 'a'] = true;
	A['n' - 'a'] = true;
	A['t' - 'a'] = true;
	A['i' - 'a'] = true;
	A['c' - 'a'] = true;

	BF(0);

	cout << MCnt;
}