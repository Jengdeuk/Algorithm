#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int N;
p S, E, M[100];

bool Dst(p A, p B)
{
	return (abs(A.first - B.first) + abs(A.second - B.second) <= 1000);
}

bool BFS()
{
	bool V[100] = {};

	queue<p> SQ;
	SQ.emplace(S);
	while (!SQ.empty())
	{
		int X = SQ.front().first;
		int Y = SQ.front().second;
		SQ.pop();

		if (Dst(p(X, Y), E))
		{
			return true;
		}

		for (int i = 0; i < N; ++i)
		{
			if (!V[i] && Dst(p(X, Y), M[i]))
			{
				V[i] = true;
				SQ.emplace(M[i]);
			}
		}
	}

	return false;
}

void Test()
{
	cin >> N;
	cin >> S.first >> S.second;
	for (int i = 0; i < N; ++i)
	{
		cin >> M[i].first >> M[i].second;
	}
	cin >> E.first >> E.second;

	if (BFS())
	{
		cout << "happy\n";
	}
	else
	{
		cout << "sad\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--)
	{
		Test();
	}
}