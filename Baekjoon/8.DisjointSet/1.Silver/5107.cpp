#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int Root[21];
bool Select[21];

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

	int TC = 1;
	while (true)
	{
		int N;
		cin >> N;
		if (N == 0) break;
		for (int i = 1; i <= N; ++i)
		{
			Root[i] = i;
			Select[i] = false;
		}

		unordered_map<string, int> Num;

		int Idx = 1;
		for (int i = 0; i < N; ++i)
		{
			string A, B;
			cin >> A >> B;
			if (Num[A] == 0) Num[A] = Idx++;
			if (Num[B] == 0) Num[B] = Idx++;
			Union(Num[A], Num[B]);
		}

		for (int i = 1; i <= N; ++i)
		{
			Select[Find(i)] = true;
		}

		int Cnt = 0;
		for (int i = 1; i <= N; ++i)
		{
			if (Select[i])
			{
				++Cnt;
			}
		}

		cout << TC++ << ' ' << Cnt << '\n';
	}
}