#include <iostream>
#include <string>
using namespace std;

bool Check[3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 3; ++i)
	{
		string Str;
		cin >> Str;
		switch (Str[0])
		{
		case 'l':
			Check[0] = true;
			break;
		case 'k':
			Check[1] = true;
			break;
		case 'p':
			Check[2] = true;
			break;
		}
	}

	bool bG = true;
	for (int i = 0; i < 3; ++i)
	{
		if (!Check[i])
		{
			bG = false;
		}
	}

	if (bG)
	{
		cout << "GLOBAL";
	}
	else
	{
		cout << "PONIX";
	}
}