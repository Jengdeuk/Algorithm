#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;

	int Cnt = 0;
	for (int i = 0; i < S.size(); ++i)
	{
		if (S[i] == 'a' || S[i] == 'e' || S[i] == 'i' || S[i] == 'o' || S[i] == 'u')
		{
			++Cnt;
		}
	}

	cout << Cnt;
}