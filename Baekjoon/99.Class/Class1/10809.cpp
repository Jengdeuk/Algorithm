#include <iostream>
#include <string>
using namespace std;

int main()
{
	string word;
	cin >> word;

	for (int i = 0; i < 26; ++i)
	{
		size_t index = word.find(97 + i);
		if (index != string::npos)
		{
			cout << index << ' ';
		}
		else
		{
			cout << "-1 ";
		}
	}
}