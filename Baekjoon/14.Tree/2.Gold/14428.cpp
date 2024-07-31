#include <iostream>
#include <cmath>
using namespace std;

typedef pair<int, int> p;

const int MaxSize = 131072 * 2;
const int MaxNum = 1000000000;

int N, K, S;
p T[MaxSize];

bool Compare(const int& L, const int& R)
{
	return (T[L].first == T[R].first ? T[L].second < T[R].second : T[L].first < T[R].first);
}

void UpdateData(int A, int B)
{
	T[A].first = B;

	while (A > 1)
	{
		int Parent = A / 2;
		if (A % 2 == 0)
		{
			if (Compare(A, A + 1))
			{
				T[Parent] = T[A];
			}
			else
			{
				T[Parent] = T[A + 1];
			}
		}
		else
		{
			if (Compare(A - 1, A))
			{
				T[Parent] = T[A - 1];
			}
			else
			{
				T[Parent] = T[A];
			}
		}

		A = Parent;
	}
}

int GetMinIndex(int A, int B)
{
	int Min = MaxNum;
	int Mi = MaxSize - 1;

	while (A <= B)
	{
		if (A % 2 == 1 && ((T[A].first < Min) || (T[A].first == Min && T[A].second < Mi)))
		{
			Min = T[A].first;
			Mi = T[A].second;
		}

		if (B % 2 == 0 && ((T[B].first < Min) || (T[B].first == Min && T[B].second < Mi)))
		{
			Min = T[B].first;
			Mi = T[B].second;
		}

		A = (A + 1) / 2;
		B = (B - 1) / 2;
	}

	return Mi;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < MaxSize; ++i)
	{
		T[i].first = MaxNum;
	}

	cin >> N;
	while (pow(2, K) < N)
	{
		++K;
	}
	S = pow(2, K);

	for (int i = 0; i < N; ++i)
	{
		cin >> T[S + i].first;
		T[S + i].second = i + 1;
	}

	for (int i = S - 1; i >= 1; --i)
	{
		int L = 2 * i;
		int R = 2 * i + 1;
		if (Compare(L, R))
		{
			T[i] = T[L];
		}
		else
		{
			T[i] = T[R];
		}
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int Op, A, B;
		cin >> Op >> A >> B;
		switch (Op)
		{
		case 1:
			UpdateData(S + A - 1, B);
			break;
	
		case 2:
			cout << GetMinIndex(S + A - 1, S + B - 1) << '\n';
			break;
		}
	}
}