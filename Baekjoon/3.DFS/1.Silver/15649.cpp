#include <iostream>
using namespace std;

int N, M;
bool Visit[8];
int Seq[8];

void Print()
{
	for (int i = 0; i < M; ++i)
	{
		cout << Seq[i] + 1 << ' ';
	}
	cout << '\n';
}

void DFS(int CurIdx)
{
	if (CurIdx == M)
	{
		Print();
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (Visit[i])
		{
			continue;
		}

		Seq[CurIdx] = i;
		Visit[i] = true;
		DFS(CurIdx + 1);
		Visit[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	DFS(0);
}