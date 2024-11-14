#include <iostream>
#include <string>
using namespace std;

int Count[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		++Count[S[0] - 'a'];
	}

	string Answer;
	for (int i = 0; i < 26; ++i)
	{
		if (Count[i] >= 5)
		{
			Answer.push_back('a' + i);
		}
	}

	if (Answer.empty())
	{
		Answer.append("PREDAJA");
	}

	cout << Answer;
}