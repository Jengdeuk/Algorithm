#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

int N;
const string Inven2[3] = { "K", "S", "A" };
const char Inven[3] = { 'K', 'S', 'A' };

queue<pair<int, string>> SQ;
unordered_map<string, bool> Visited;

bool Check(string Current)
{
	if (Current.size() != N)
	{
		return false;
	}

	for (int i = 0; i < N; ++i)
	{
		if (i % 3 == 0 && Current[i] != 'K')
		{
			return false;
		}

		if (i % 3 == 1 && Current[i] != 'S')
		{
			return false;
		}

		if (i % 3 == 2 && Current[i] != 'A')
		{
			return false;
		}
	}

	return true;
}

int BFS(string Start)
{
	int Cnt = 0;

	SQ.emplace(Cnt, Start);
	while (!SQ.empty())
	{
		int CurCnt = SQ.front().first;
		string CurStr = SQ.front().second;
		SQ.pop();

		if (Visited[CurStr])
		{
			continue;
		}

		Visited[CurStr] = true;

		if (Check(CurStr))
		{
			Cnt = CurCnt;
			break;
		}

		// #1
		if (CurStr.size() == N)
		{
			for (int i = 0; i < CurStr.size(); ++i)
			{
				string NewStr = CurStr;
				NewStr.erase(NewStr.begin() + i);
				if (!Visited[NewStr])
				{
					SQ.emplace(CurCnt + 1, NewStr);
				}
			}
		}

		if (CurStr.size() == N - 1)
		{
			// #2
			for (int i = 0; i < 3; ++i)
			{
				string NewStr = CurStr;
				NewStr.insert(0, Inven2[i]);
				if (!Visited[NewStr])
				{
					SQ.emplace(CurCnt + 1, NewStr);
				}
			}

			// #3
			for (int i = 0; i < 3; ++i)
			{
				string NewStr = CurStr;
				NewStr.push_back(Inven[i]);
				if (!Visited[NewStr])
				{
					SQ.emplace(CurCnt + 1, NewStr);
				}
			}
		}
	}

	return Cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string X;
	cin >> X;
	N = X.size();
	cout << BFS(X);
}