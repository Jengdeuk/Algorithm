#include <iostream>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;

bool Check[10];

bool Again()
{
	for (int i = 0; i < 10; ++i)
	{
		if (!Check[i])
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		ll N = 0;
		cin >> N;
		if (N == 0)
		{
			break;
		}

		memset(Check, false, sizeof(Check));
		ll Mul = 0;
		do
		{
			++Mul;
			string S = to_string(N * Mul);
			for (int j = 0; j < S.size(); ++j)
			{
				Check[S[j] - '0'] = true;
			}
		} while (Again());

		cout << Mul << '\n';
	}
}