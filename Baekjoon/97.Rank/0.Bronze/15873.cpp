#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;

	int N = S.size();
	if (S[0] == '1' && S[1] == '0')
	{
		cout << 10 + stoi(S.substr(2, N - 2));
	}
	else
	{
		cout << (S[0] - '0') + stoi(S.substr(1, N - 1));
	}
}