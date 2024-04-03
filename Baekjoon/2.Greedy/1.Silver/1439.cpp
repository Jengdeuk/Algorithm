#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;

	int Cnt = 0;
	for (int i = 0; i < S.size() - 1; ++i)
	{
		if (S[i] != S[i + 1])
		{
			++Cnt;
		}
	}

	cout << ceil(Cnt / 2.f);
}