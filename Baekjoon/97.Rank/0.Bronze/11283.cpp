#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;
	cout << ((S[0] & 255) - 234) * 4096 + ((S[1] & 255) - 176) * 64 + (S[2] & 255) - 127;
}