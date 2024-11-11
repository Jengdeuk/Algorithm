#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;

	int Sum = 10;
	for (int i = 1; i < S.size(); ++i)
	{
		if (S[i] == S[i - 1])
		{
			Sum += 5;
		}
		else
		{
			Sum += 10;
		}
	}

	cout << Sum;
}