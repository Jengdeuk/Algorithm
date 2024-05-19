#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> p;

int N, Cnt;
p Point[50];
int Sol[4];

ll Func(int A, int B, int C)
{
	return (Point[B].first - Point[A].first) * (Point[C].second - Point[A].second) - (Point[B].second - Point[A].second) * (Point[C].first - Point[A].first);
}

bool Check()
{
	int A = Sol[0], B = Sol[1], C = Sol[2], D = Sol[3];

	int Num = (Func(A, B, C) * Func(A, B, D) < 0 ? 1 : 0);
	Num += (Func(A, C, B) * Func(A, C, D) < 0 ? 1 : 0);
	Num += (Func(A, D, B) * Func(A, D, C) < 0 ? 1 : 0);
	Num += (Func(B, C, A) * Func(B, C, D) < 0 ? 1 : 0);
	Num += (Func(B, D, A) * Func(B, D, C) < 0 ? 1 : 0);
	Num += (Func(C, D, A) * Func(C, D, B) < 0 ? 1 : 0);

	if (Num == 2)
	{
		return true;
	}
	
	return false;
}

void DFS(int Cur, int Idx)
{
	if (Idx == 4)
	{
		if (Check())
		{
			++Cnt;
		}

		return;
	}

	if (Cur >= N)
	{
		return;
	}

	Sol[Idx] = Cur;
	DFS(Cur + 1, Idx + 1);
	DFS(Cur + 1, Idx);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Point[i].first >> Point[i].second;
	}

	DFS(0, 0);
	cout << Cnt;
}