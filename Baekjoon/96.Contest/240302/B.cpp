#include <iostream>
#include <string>
using namespace std;

int CountItem(const string& S)
{
	string Item;
	int Num;
	cin >> Item >> Num;

	int FindIndex = Item.find('_');
	if (FindIndex == string::npos)
	{
		if (Item.compare(S) == 0)
		{
			return Num;
		}
		else
		{
			return 0;
		}
	}

	int PrevIndex = 0;
	while (FindIndex != string::npos)
	{
		string Word = Item.substr(PrevIndex, FindIndex - PrevIndex);
		if (Word.compare(S) == 0)
		{
			return Num;
		}

		PrevIndex = FindIndex + 1;
		FindIndex = Item.find('_', PrevIndex);
	}

	string Word = Item.substr(PrevIndex);
	if (Word.compare(S) == 0)
	{
		return Num;
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	string S;
	cin >> N >> S;

	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		Cnt += CountItem(S);
	}

	cout << Cnt;
}