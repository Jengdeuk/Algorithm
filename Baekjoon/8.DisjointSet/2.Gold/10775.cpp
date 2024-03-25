#include <iostream>
using namespace std;

bool LandingGate[100001];
int Root[100001];

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

	for (int i = 1; i <= 100000; ++i)
	{
		Root[i] = i;
	}

	int G, P;
	cin >> G >> P;

	int Cnt = 0;
	for (int i = 1; i <= P; ++i)
	{
		int g;
		cin >> g;
		if ((g = Find(g)) == 0)
		{
			break;
		}

		Union(g, g - 1);
		++Cnt;
	}

	cout << Cnt;
}