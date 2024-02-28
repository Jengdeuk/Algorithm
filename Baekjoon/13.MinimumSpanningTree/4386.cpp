#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef pair<float, float> star;
typedef tuple<float, int, int> edge;

vector<star> Stars;
vector<edge> EdgeList;
int Root[100];

float MakeDistance(const star& A, const star& B)
{
	float AX = A.first, AY = A.second;
	float BX = B.first, BY = B.second;

	return sqrtf((AX - BX) * (AX - BX) + (AY - BY) * (AY - BY));
}

int Find(int Node)
{
	if (Node == Root[Node])
	{
		return Node;
	}

	return Root[Node] = Find(Root[Node]);
}

void Union(int A, int B)
{
	int RootA = Find(A);
	int RootB = Find(B);

	int NewRoot = min(RootA, RootB);
	Root[RootA] = NewRoot;
	Root[RootB] = NewRoot;
}

void Init(int N)
{
	Stars.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		float X, Y;
		cin >> X >> Y;
		Stars.emplace_back(X, Y);
	}

	EdgeList.reserve(N * N);
	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			EdgeList.emplace_back(MakeDistance(Stars[i], Stars[j]), i, j);
		}
	}

	sort(EdgeList.begin(), EdgeList.end());

	for (int i = 0; i < N; ++i)
	{
		Root[i] = i;
	}
}

float Kruskal(int N)
{
	int CntEdge = 0;
	float CntDistance = 0;
	while (CntEdge < N - 1)
	{
		for (int i = 0; i < EdgeList.size(); ++i)
		{
			int A = get<1>(EdgeList[i]);
			int B = get<2>(EdgeList[i]);

			if (Find(A) != Find(B))
			{
				Union(A, B);
				CntDistance += get<0>(EdgeList[i]);
				++CntEdge;
			}
		}
	}

	return CntDistance;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	Init(N);

	cout << fixed;
	cout.precision(2);
	cout << Kruskal(N);
}