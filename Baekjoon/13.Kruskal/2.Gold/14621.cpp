#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;

int N, R[1001];
bool M[1001];

vector<ip> E;

int Find(int N)
{
	if (N == R[N])
	{
		return N;
	}

	return (R[N] = Find(R[N]));
}

void Union(int A, int B)
{
	R[Find(A)] = Find(B);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int L;
	cin >> N >> L;
	for (int i = 1; i <= N; ++i)
	{
		char Ch;
		cin >> Ch;
		if (Ch == 'M')
		{
			M[i] = true;
		}

		R[i] = i;
	}

	while (L--)
	{
		int A, B, D;
		cin >> A >> B >> D;
		E.emplace_back(D, p(A, B));
	}

	sort(E.begin(), E.end());

	int Cnt = 0, Sum = 0;
	while (Cnt < N - 1)
	{
		bool bFind = false;
		for (const ip& Edge : E)
		{
			int D = Edge.first;
			int A = Edge.second.first;
			int B = Edge.second.second;
			if (M[A] != M[B] && Find(A) != Find(B))
			{
				bFind = true;
				Cnt++;
				Sum += D;
				Union(A, B);
				break;
			}
		}

		if (bFind == false)
		{
			break;
		}
	}

	if (Cnt == N - 1)
	{
		cout << Sum;
	}
	else
	{
		cout << -1;
	}
}