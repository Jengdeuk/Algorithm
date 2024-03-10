#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
using namespace std;

unordered_map<string, list<string>> Codes;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;

		string Title;
		cin >> Title;
		cin.ignore();

		string Code;
		getline(cin, Code);

		string SameCode = Code.substr(0, 5);
		Codes[SameCode].emplace_back(Title);
	}

	for (int i = 0; i < M; ++i)
	{
		string SameCode;
		getline(cin, SameCode);

		if (Codes[SameCode].size() > 1)
		{
			cout << "?\n";
		}
		else if (Codes[SameCode].size() == 1)
		{
			cout << Codes[SameCode].front() << '\n';
		}
		else
		{
			cout << "!\n";
		}
	}
}