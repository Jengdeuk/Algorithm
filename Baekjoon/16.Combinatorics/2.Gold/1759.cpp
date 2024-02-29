#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> Alphabets;

void DFS(string PW, int CurAlphabetIndex)
{
	if (PW.size() == L)
	{
		int Parent = 0;
		int Child = 0;
		for (int i = 0; i < L; ++i)
		{
			if (PW[i] == 'a'
				|| PW[i] == 'e'
				|| PW[i] == 'i'
				|| PW[i] == 'o'
				|| PW[i] == 'u')
			{
				++Parent;
			}
			else
			{
				++Child;
			}
		}
		if (Parent >= 1
			&& Child >= 2)
		{
			cout << PW << '\n';
		}

		return;
	}
	else if (CurAlphabetIndex == C)
	{
		return;
	}

	string OriginPW = PW;
	string NewPW = PW;
	NewPW.push_back(Alphabets[CurAlphabetIndex]);

	DFS(NewPW, CurAlphabetIndex + 1);
	DFS(OriginPW, CurAlphabetIndex + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> L >> C;

	Alphabets.reserve(C);
	for (int i = 0; i < C; ++i)
	{
		char Alphabet;
		cin >> Alphabet;
		Alphabets.emplace_back(Alphabet);
	}

	sort(Alphabets.begin(), Alphabets.end());

	DFS("", 0);
}