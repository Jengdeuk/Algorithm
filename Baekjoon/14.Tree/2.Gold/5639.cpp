#include <iostream>
using namespace std;

int Tree[10001];

void DFS(int Current, int End)
{
	if (Current > End)
	{
		return;
	}
	
	int Mid = End + 1;
	for (int i = Current + 1; i <= End; ++i)
	{
		if (Tree[i] > Tree[Current])
		{
			Mid = i;
			break;
		}
	}

	DFS(Current + 1, Mid - 1);
	DFS(Mid, End);
	cout << Tree[Current] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int i = 0;
	while (true) { cin >> Tree[i]; if (Tree[i] == 0) break; ++i; }

	DFS(0, i - 1);
}