#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string Str;
	getline(cin, Str);
	for (int i = 0; i < Str.size(); ++i)
	{
		if (Str[i] >= 'A' && Str[i] <= 'Z')
		{
			cout << char((Str[i] + 13 > 'Z') ? Str[i] - 13 : Str[i] + 13);
		}
		else if (Str[i] >= 'a' && Str[i] <= 'z')
		{
			cout << char((Str[i] + 13 > 'z') ? Str[i] - 13 : Str[i] + 13);
		}
		else
		{
			cout << Str[i];
		}
	}
}