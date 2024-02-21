#include <iostream>
#include <string>
using namespace std;

string Word;
int Alphabet[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> Word;
	for (int i = 0; i < Word.length(); ++i)
	{
		++Alphabet[Word[i] - 'a'];
	}

	for (int i = 0; i < 26; ++i)
	{
		cout << Alphabet[i] << ' ';
	}
}