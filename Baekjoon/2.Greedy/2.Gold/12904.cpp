#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S, T;
	cin >> S >> T;

	while (S.size() < T.size())
	{
		char C = T.back();
		T.pop_back();

		if (C == 'B')
		{
			reverse(T.begin(), T.end());
		}
	}

	cout << (S.compare(T) == 0);
}