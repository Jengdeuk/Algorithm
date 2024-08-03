#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;

	for (int L = 1; L <= S.size(); ++L)
	{
		for (int i = 0; i < S.size(); ++i)
		{
			if (i + L > S.size())
			{
				break;
			}

			string Sub = S.substr(i, L);
			++M[Sub];
		}
	}

	cout << M.size();
}