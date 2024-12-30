#include <iostream>
#include <string>
#include <queue>
using namespace std;

void Test()
{
	string S;
	getline(cin, S);

	int Idx = 0;
	string Temp;
	for (int i = 0; i < S.size(); ++i)
	{
		if (S[i] == ' ')
		{
			Idx = i + 1;
			break;
		}

		Temp.push_back(S[i]);
	}

	float Num = stof(Temp);
	Temp.clear();

	queue<char> Q;
	for (int i = Idx; i < S.size(); ++i)
	{
		if (S[i] != ' ')
		{
			Q.emplace(S[i]);
		}
	}

	while (!Q.empty())
	{
		switch (Q.front())
		{
		case '@':
			Num *= 3;
			break;
		
		case '%':
			Num += 5;
			break;

		case '#':
			Num -= 7;
			break;
		}
		Q.pop();
	}

	cout << fixed;
	cout.precision(2);
	cout << Num << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	cin.ignore();
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}