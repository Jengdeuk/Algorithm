#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string Str;
	cin >> Str;
	for (int i = 0; i < Str.size(); ++i)
	{
		if (Str[i] < 'a')
		{
			cout << char(Str[i] + 32);
		}
		else
		{
			cout << char(Str[i] - 32);
		}
	}
}