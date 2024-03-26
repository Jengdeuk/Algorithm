#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

unordered_set<string> StrSet;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string Str;
		cin >> Str;
		StrSet.emplace(Str);
	}

	int Cnt = 0;
	for (int i = 0; i < M; ++i)
	{
		string Str;
		cin >> Str;
		if (StrSet.count(Str) > 0)
		{
			++Cnt;
		}
	}

	cout << Cnt;
}