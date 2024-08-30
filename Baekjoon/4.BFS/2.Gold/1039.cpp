#include <iostream>
#include <string>
#include <queue>
using namespace std;

typedef pair<string, int> p;

string N;
int M, K, Max;
bool V[10000000][11];

void BFS()
{
	queue<p> Q;
	V[stoi(N)][0] = true;
	Q.emplace(N, 0);
	while (!Q.empty())
	{
		string Cur = Q.front().first;
		int Cnt = Q.front().second;
		Q.pop();

		if (Cnt == K)
		{
			Max = max(Max, stoi(Cur));
			continue;
		}

		for (int i = 0; i < M; ++i)
		{
			for (int j = i + 1; j < M; ++j)
			{
				if (i == 0 && Cur[j] == '0')
				{
					continue;
				}

				string Nxt(Cur);
				char Temp = Nxt[i];
				Nxt[i] = Nxt[j];
				Nxt[j] = Temp;
				if (!V[stoi(Nxt)][Cnt + 1])
				{
					V[stoi(Nxt)][Cnt + 1] = true;
					Q.emplace(Nxt, Cnt + 1);
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Temp;
	cin >> Temp >> K;

	N = to_string(Temp);
	M = N.size();

	BFS();

	if (Max > 0)
	{
		cout << Max;
	}
	else
	{
		cout << -1;
	}
}