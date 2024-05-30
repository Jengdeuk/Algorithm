#include <iostream>
using namespace std;

int Root[1000000];

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

void Test()
{
	int N, K;
	cin >> N >> K;

	for (int i = 0; i < N; ++i)
	{
		Root[i] = i;
	}

	for (int i = 0; i < K; ++i)
	{
		int A, B;
		cin >> A >> B;
		Union(A, B);
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		cout << (Find(A) == Find(B)) << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		cout << "Scenario " << i << ":\n";
		Test();
		cout << '\n';
	}
}