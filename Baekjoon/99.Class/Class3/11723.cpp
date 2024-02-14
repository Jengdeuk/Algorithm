#include <iostream>
#include <string>
#include <bitset>
using namespace std;

int Set;

void Command()
{
	string First;
	getline(cin, First);

	int Second = 0;
	int FindIndex = First.find(' ');
	if (FindIndex != string::npos)
	{
		Second = stoi(First.substr(FindIndex + 1));
		First = First.substr(0, FindIndex);
	}

	if (First.compare("add") == 0)
	{
		Set = Set | (1 << (Second - 1));
	}
	else if (First.compare("remove") == 0)
	{
		Set = Set & ~(1 << (Second - 1));
	}
	else if (First.compare("check") == 0)
	{
		if ((Set & (1 << (Second - 1))) == 0)
		{
			cout << 0 << '\n';
		}
		else
		{
			cout << 1 << '\n';
		}
	}
	else if (First.compare("toggle") == 0)
	{
		Set = Set ^ (1 << (Second - 1));
	}
	else if (First.compare("all") == 0)
	{
		Set = 0b11111111111111111111;
	}
	else if (First.compare("empty") == 0)
	{
		Set = 0b00000000000000000000;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M;
	cin >> M;
	cin.ignore();

	for (int i = 0; i < M; ++i)
	{
		Command();
	}
}