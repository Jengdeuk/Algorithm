#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char> Stick;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string Str;
	cin >> Str;

	int Cnt = 0;
	bool bLaser = false;
	for (int i = 0; i < Str.size(); ++i)
	{
		char ch = Str[i];
		switch (ch)
		{
		case '(':
			bLaser = true;
			Stick.emplace(ch);
			break;
		case ')':
			Stick.pop();
			if (bLaser)
			{
				Cnt += Stick.size();
			}
			else
			{
				++Cnt;
			}
			bLaser = false;
			break;
		}
	}

	cout << Cnt;
}