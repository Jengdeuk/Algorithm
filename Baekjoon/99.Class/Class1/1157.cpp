#include <iostream>
#include <string>
using namespace std;

int main()
{
	int alphabete[26] = {};

	string word;
	cin >> word;

	for (int i = 0; i < 26; ++i)
	{
		for (const char& character : word)
		{
			if (character == 65 + i
				|| character == 97 + i)
			{
				++alphabete[i];
			}
		}
	}

	int maxIndex = 0, duplicateCount = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (i != 0
			&& alphabete[i] == alphabete[maxIndex])
		{
			++duplicateCount;
		}

		if (alphabete[i] > alphabete[maxIndex])
		{
			maxIndex = i;
			duplicateCount = 0;
		}
	}

	char mostAlphabet = (0 < duplicateCount) ? '?' : 65 + maxIndex;
	cout << mostAlphabet;
}