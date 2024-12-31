#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	getline(cin, S);

	int HCnt = 0, SCnt = 0;
	for (int i = 0; i < S.size() - 2; ++i)
	{
		if (S[i] == ':' && S[i + 1] == '-')
		{
			if (S[i + 2] == ')')
			{
				++HCnt;
				i += 2;
			}
			else if (S[i + 2] == '(')
			{
				++SCnt;
				i += 2;
			}
		}
	}

	if (HCnt == 0 && SCnt == 0)
	{
		cout << "none";
	}
	else if (HCnt == SCnt)
	{
		cout << "unsure";
	}
	else if (HCnt > SCnt)
	{
		cout << "happy";
	}
	else
	{
		cout << "sad";
	}
}