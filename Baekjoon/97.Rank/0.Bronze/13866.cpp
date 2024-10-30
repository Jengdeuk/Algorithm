#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int S[4];
	for (int i = 0; i < 4; ++i)
	{
		cin >> S[i];
	}

	cout << abs((S[0] + S[3]) - (S[1] + S[2]));
}