#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

typedef pair<string, int> p;

const string Solution("123456780");

const int Dir[9][4] =
{
	{ 1, 3, -1, -1 }, { 0, 2, 4, -1 }, { 1, 5, -1, -1 },
	{ 0, 4, 6, -1 }, { 1, 3, 5, 7 }, { 2, 4, 8, -1 },
	{ 3, 7, -1, -1 }, { 4, 6, 8, -1 }, { 5, 7, -1, -1}
};

unordered_map<string, int> M;

int TakePos(string& S)
{
	for (int i = 0; i < 9; ++i)
	{
		if (S[i] == '0')
		{
			return i;
		}
	}

	return -1;
}

int BFS(string& Start)
{
	queue<p> Q;
	M[Start] = 0;
	Q.emplace(Start, 0);
	while (!Q.empty())
	{
		string Cur = Q.front().first;
		int Step = Q.front().second;
		Q.pop();

		if (Cur.compare(Solution) == 0)
		{
			return Step;
		}

		int ZeroPos = TakePos(Cur);
		for (int i = 0; i < 4; ++i)
		{
			int NxtPos = Dir[ZeroPos][i];
			if (NxtPos == -1)
			{
				continue;
			}

			string Nxt(Cur);
			Nxt[ZeroPos] = Nxt[NxtPos];
			Nxt[NxtPos] = '0';
			if (M.count(Nxt))
			{
				continue;
			}

			M[Nxt] = Step + 1;
			Q.emplace(Nxt, Step + 1);
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string Start;
	for (int i = 0; i < 9; ++i)
	{
		char Ch;
		cin >> Ch;
		Start.push_back(Ch);
	}

	cout << BFS(Start);
}