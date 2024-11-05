#include <iostream>
#include <string>
using namespace std;

void Test()
{
	string S;
	cin >> S;

	bool bPalindrome = true;

	int Count = 0;
	int L = 0, R = S.size() - 1;
	while (L < R)
	{
		++Count;
		if (S[L] != S[R])
		{
			bPalindrome = false;
			break;
		}
		++L;
		--R;
	}

	if (bPalindrome)
	{
		++Count;
	}

	cout << bPalindrome << ' ' << Count << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}