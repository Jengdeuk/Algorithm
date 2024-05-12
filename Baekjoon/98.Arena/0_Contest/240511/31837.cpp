#include <iostream>
#include <string>
#include <list>
using namespace std;

typedef pair<int, int> cd;
typedef pair<string, string> se;
typedef pair<cd, se> ci;

int N, Cnt;
list<ci> Group[15];

bool Sel[15];
ci Sol[15];

bool CheckC()
{
	int C = 0;
	for (int i = 0; i < N; ++i)
	{
		if (Sel[i])
		{
			C += Sol[i].first.first;
		}
	}

	if (C == 22)
	{
		return true;
	}
	
	return false;
}

bool CheckT()
{
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (!Sel[i] || !Sel[j] || Sol[i].first.second != Sol[j].first.second)
			{
				continue;
			}

			int IS = stoi((Sol[i].second.first).substr(0, 2)) * 60 + stoi((Sol[i].second.first).substr(3, 2));
			int IE = stoi((Sol[i].second.second).substr(0, 2)) * 60 + stoi((Sol[i].second.second).substr(3, 2));

			int JS = stoi((Sol[j].second.first).substr(0, 2)) * 60 + stoi((Sol[j].second.first).substr(3, 2));
			int JE = stoi((Sol[j].second.second).substr(0, 2)) * 60 + stoi((Sol[j].second.second).substr(3, 2));

			if ((JS > IS && JS < IE) || (JE > IS && JE < IE)
				|| (JS <= IS && JE > IS && JE <= IE) || (JE >= IE && JS >= IS && JS < IE)
				|| (IS > JS && IS < JE) || (IE > JS && IE < JE)
				|| (IS <= JS && IE > JS && IE <= JE) || (IE >= JE && IS >= JS && IS < JE))
			{
				return false;
			}
		}
	}

	return true;
}

void DFS(int Idx)
{
	if (Idx == N)
	{
		if (CheckC() && CheckT())
		{
			++Cnt;
		}

		return;
	}

	if (Group[Idx].size() > 0)
	{
		Sel[Idx] = true;
		for (const ci& ClassInfo : Group[Idx])
		{
			Sol[Idx] = ClassInfo;
			DFS(Idx + 1);
		}
	}

	Sel[Idx] = false;
	DFS(Idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int A;
		cin >> A;
		for (int j = 0; j < A; ++j)
		{
			int C, D;
			cin >> C >> D;
			string S, E;
			cin >> S >> E;
			Group[i].emplace_back(ci(cd(C, D), se(S, E)));
		}
	}

	DFS(0);

	cout << Cnt;
}