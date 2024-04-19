#include <iostream>
#include <algorithm>
using namespace std;

int N, M, K;
int Blue[4000001];
int Root[4000001];

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
	int Max = max(A, B);
	Root[A] = Max;
	Root[B] = Max;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;

	for (int i = 0; i < M; ++i)
	{
		cin >> Blue[i];
	}

	sort(Blue, Blue + M);
	for (int i = 0; i < M; ++i)
	{
		Root[Blue[i]] = Blue[i];
	}

	for (int i = 0; i < K; ++i)
	{
		int Red;
		cin >> Red;

		int Index = upper_bound(Blue, Blue + M, Red) - Blue;
		int Num = Find(Blue[Index]);
		cout << Num << '\n';

		int NewIndex = lower_bound(Blue, Blue + M, Num) - Blue;
		Union(Blue[NewIndex], Blue[NewIndex + 1]);
	}
}