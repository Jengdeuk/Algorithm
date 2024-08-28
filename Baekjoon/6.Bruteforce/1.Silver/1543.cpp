#include <iostream>
#include <string>
using namespace std;

int SS, QS;
string S, Q;

bool IsIncluded(int SI)
{
	for (int i = 0; i < QS; ++i)
	{
		if (S[SI + i] != Q[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	getline(cin, S);
	getline(cin, Q);

	SS = S.size();
	QS = Q.size();

	int Cnt = 0;
	for (int i = 0; i < SS; ++i)
	{
		if (IsIncluded(i))
		{
			++Cnt;
			i += QS - 1;
		}
	}

	cout << Cnt;
}