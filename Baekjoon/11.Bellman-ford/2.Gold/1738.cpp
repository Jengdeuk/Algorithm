#include <iostream>
#include <climits>
#include <list>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> pp;

const int IInf = INT_MIN;

int N, M;
list<pp> Edge;
int Cost[101];
int Pred[101];
list<int> Way;
bool Visited[101];

bool BellmanFord();
void TraceWay(int Node);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int U, V, W;
		cin >> U >> V >> W;
		Edge.emplace_back(W, p(U, V));
	}

	if (BellmanFord())
	{
		for (const int& Node : Way)
		{
			cout << Node << ' ';
		}
	}
	else
	{
		cout << -1;
	}
}

bool BellmanFord()
{
	for (int i = 1; i <= N; ++i)
	{
		Cost[i] = IInf;
	}
	Cost[1] = 0;
	Pred[1] = 0;

	for (int i = 0; i < 1000; ++i)
	{
		for (const pp& e : Edge)
		{
			int W = e.first;
			int U = e.second.first;
			int V = e.second.second;
			if (Cost[U] == IInf)
			{
				continue;
			}

			int NewCst = Cost[U] + W;
			if (NewCst > Cost[V])
			{
				Cost[V] = NewCst;
				Pred[V] = U;
			}
		}
	}

	TraceWay(N);
	if (Way.front() != 1)
	{
		return false;
	}

	for (const pp& e : Edge)
	{
		int W = e.first;
		int U = e.second.first;
		int V = e.second.second;
		if (Cost[U] == IInf || Way.end() == find(Way.begin(), Way.end(), V))
		{
			continue;
		}

		if (Cost[U] + W > Cost[V])
		{
			return false;
		}
	}

	return true;
}

void TraceWay(int Node)
{
	if (Visited[Node])
	{
		return;
	}

	Visited[Node] = true;
	if (Pred[Node] == 0)
	{
		Way.emplace_back(Node);
		return;
	}

	TraceWay(Pred[Node]);
	Way.emplace_back(Node);
}