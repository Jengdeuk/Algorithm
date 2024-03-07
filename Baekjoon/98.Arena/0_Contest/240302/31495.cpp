#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string str;
	getline(cin, str);

	if (str.size() > 2
		&&
		((str.front() == '"' && str.back() == '"')
		|| (str.front() == '\"' && str.back() == '\"')))
	{
		cout << str.substr(1, str.size() - 2);
	}
	else
	{
		cout << "CE";
	}
}