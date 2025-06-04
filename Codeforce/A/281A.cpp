#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;
	if (S[0] >= 'a')
	{
		S[0] -= 32;
	}

	cout << S;
}