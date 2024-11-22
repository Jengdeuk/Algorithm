#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	while (getline(cin, S))
	{
		int C[4] = {};
		for (int i = 0; i < S.size(); ++i)
		{
			int Idx;
			if (S[i] >= 'a' && S[i] <= 'z')
			{
				Idx = 0;
			}
			else if (S[i] >= 'A' && S[i] <= 'Z')
			{
				Idx = 1;
			}
			else if (S[i] >= '0' && S[i] <= '9')
			{
				Idx = 2;
			}
			else
			{
				Idx = 3;
			}
			++C[Idx];
		}

		for (int i = 0; i < 4; ++i)
		{
			cout << C[i] << ' ';
		}
		cout << '\n';
	}
}