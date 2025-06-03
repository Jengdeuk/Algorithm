#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;

	set<char> Check;
	for (int i = 0; i < S.size(); ++i)
	{
		Check.emplace(S[i]);
	}

	if (Check.size() % 2 == 0)
	{
		cout << "CHAT WITH HER!";
	}
	else
	{
		cout << "IGNORE HIM!";
	}
}