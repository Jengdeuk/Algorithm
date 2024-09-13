#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;

	bool bFound = false;
	for (int i = 1; i < S.size(); ++i)
	{
		int LSum = 1;
		for (int j = 0; j < i; ++j)
		{
			LSum *= S[j] - '0';
		}

		int RSum = 1;
		for (int j = i; j < S.size(); ++j)
		{
			RSum *= S[j] - '0';
		}

		if (LSum == RSum)
		{
			bFound = true;
			break;
		}
	}

	if (bFound)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}