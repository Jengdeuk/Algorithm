#include <iostream>
#include <cstring>
using namespace std;

int N, Cnt;
int Student[100000];
bool Visited[100000];
bool Check[100000];

void DFS(int Current)
{
	Visited[Current] = true;

	int Next = Student[Current];
	if (!Visited[Next])
	{
		DFS(Next);
	}
	else if (!Check[Next])
	{
		for (int i = Next; i != Current; i = Student[i])
		{
			++Cnt;
		}

		++Cnt;
	}

	Check[Current] = true;
}

void Test()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;
		Student[i] = Num - 1;
	}
	
	memset(Visited, false, sizeof(Visited));
	memset(Check, false, sizeof(Check));

	Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		if (!Check[i])
		{
			DFS(i);
		}
	}

	cout << N - Cnt << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}