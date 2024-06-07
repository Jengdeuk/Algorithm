#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N, M, K;
p A[100], B[100];
int C[100];

bool Compare(const p& L, const p& R)
{
	return (L.first == R.first ? L.second < R.second : L.first > R.first);
}

bool FindElem(int &I, int &J, int AI, int BI)
{
	while (A[I].second <= AI || B[J].second <= BI
		|| A[I].first != B[J].first)
	{
		while (A[I].second <= AI)
		{
			if (++I >= N)
			{
				return false;
			}
		}

		while (B[J].second <= BI)
		{
			if (++J >= M)
			{
				return false;
			}
		}

		if (A[I].first == B[J].first)
		{
			break;
		}

		if (A[I].first > B[J].first)
		{
			if (++I >= N)
			{
				return false;
			}
		}
		else
		{
			if (++J >= M)
			{
				return false;
			}
		}
	}

	C[K++] = A[I].first;

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i].first;
		A[i].second = i;
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> B[i].first;
		B[i].second = i;
	}

	sort(A, A + N, Compare);
	sort(B, B + M, Compare);
	
	int i = 0, j = 0;
	int AI = -1, BI = -1;
	while (FindElem(i, j, AI, BI))
	{
		AI = A[i].second;
		BI = B[j].second;
	}

	cout << K << '\n';
	for (int i = 0; i < K; ++i)
	{
		cout << C[i] << ' ';
	}
}