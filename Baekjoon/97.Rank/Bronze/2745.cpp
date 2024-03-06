#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string N;
	int B;
	cin >> N >> B;

	int Result = 0;
	int Cnt = 0;
	for (int i = N.size() - 1; i >= 0; --i)
	{
		char ch = N[i];
		if (ch < 'A')
		{
			Result += (ch - '0') * pow(B, Cnt);
		}
		else
		{
			Result += (ch - 'A' + 10) * pow(B, Cnt);
		}
		++Cnt;
	}

	cout << Result;
}