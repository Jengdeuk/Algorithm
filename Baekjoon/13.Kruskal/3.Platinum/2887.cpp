#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> edge;

int N;
p PX[100000];
p PY[100000];
p PZ[100000];
priority_queue<edge, vector<edge>, greater<edge>> Edge;

int Root[100000];

int Find(int Node)
{
	if (Node == Root[Node])
	{
		return Node;
	}

	return Root[Node] = Find(Root[Node]);
}

void Union(int NodeA, int NodeB)
{
	int A = Find(NodeA);
	int B = Find(NodeB);
	int Min = min(A, B);
	Root[A] = Min;
	Root[B] = Min;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> PX[i].first >> PY[i].first >> PZ[i].first;
		PX[i].second = i;
		PY[i].second = i;
		PZ[i].second = i;
	}

	sort(PX, PX + N);
	sort(PY, PY + N);
	sort(PZ, PZ + N);

	for (int i = 0; i < N; ++i)
	{
		Root[i] = i;
		if (i == N - 1)
		{
			break;
		}

		Edge.emplace(abs(PX[i].first - PX[i + 1].first), p(PX[i].second, PX[i + 1].second));
		Edge.emplace(abs(PY[i].first - PY[i + 1].first), p(PY[i].second, PY[i + 1].second));
		Edge.emplace(abs(PZ[i].first - PZ[i + 1].first), p(PZ[i].second, PZ[i + 1].second));
	}

	int EdgeNum = 0;
	long long Weight = 0;
	while (!Edge.empty() && EdgeNum < N - 1)
	{
		int W = Edge.top().first;
		int A = Edge.top().second.first;
		int B = Edge.top().second.second;
		Edge.pop();
		if (Find(A) == Find(B))
		{
			continue;
		}

		Union(A, B);
		Weight += W;
		++EdgeNum;
	}

	cout << Weight;
}