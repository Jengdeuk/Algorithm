#include <iostream>
#include <string>
using namespace std;

int main()
{
	string sentence;
	getline(cin, sentence);

	int wordsNumber = 1;

	if (sentence.length() == 1 && sentence.front() == ' ')
	{
		wordsNumber = 0;
		cout << wordsNumber;

		return 0;
	}

	for (int i = 0; i < sentence.length(); ++i)
	{
		if ((i != 0 && i != sentence.length() - 1)
			&& sentence[i] == ' ')
		{
			++wordsNumber;
		}
	}
	cout << wordsNumber;
}