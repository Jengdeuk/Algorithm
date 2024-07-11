#include <iostream>
#include <cstring>
using namespace std;

int N;
int S[101];
bool V[101], C[101];

bool DFS(int Start, int Current)
{
	V[Current] = true;

	int Next = S[Current];
	if (Next == Start)
	{
		return C[Current] = true;
	}

	if (V[Next] || C[Next])
	{
		return C[Current] = false;
	}

	return C[Current] = DFS(Start, Next);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> S[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		if (C[i])
		{
			continue;
		}

		memset(V, false, sizeof(V));
		DFS(i, i);
	}

	int Cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		Cnt += (C[i] ? 1 : 0);
	}

	cout << Cnt << "\n";
	for (int i = 1; i <= N; ++i)
	{
		if (C[i])
		{
			cout << i << "\n";
		}
	}
}