#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	bool bFound = false;
	while (N > 4)
	{
		string S = to_string(N);

		bFound = true;
		for (int i = 0; i < S.size(); ++i)
		{
			if (S[i] != '4' && S[i] != '7')
			{
				bFound = false;
				break;
			}
		}

		if (bFound)
		{
			break;
		}

		--N;
	}

	if (bFound)
	{
		cout << N;
	}
	else
	{
		cout << 4;
	}
}