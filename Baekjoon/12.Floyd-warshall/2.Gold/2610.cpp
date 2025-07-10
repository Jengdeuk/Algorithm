#include <iostream>
#include <climits>
#include <set>
using namespace std;

typedef pair<int, int> p;

const int Inf = INT_MAX;

int N, M, D[101][101], MD[101], R[101];
p Lines[10000];
set<int> Answer;

int Find(int A)
{
	if (R[A] == A)
	{
		return A;
	}

	return R[A] = Find(R[A]);
}

void Union(int A, int B)
{
	if (A > B)
	{
		int Temp = A;
		A = B;
		B = Temp;
	}

	int RA = Find(A);
	int RB = Find(B);
	if (MD[RA] <= MD[RB])
	{
		R[RB] = RA;
	}
	else
	{
		R[RA] = RB;
	}
}

void Initialize()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		R[i] = i;

		for (int j = 1; j <= N; ++j)
		{
			if (i == j)
			{
				continue;
			}

			D[i][j] = Inf;
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		Lines[i] = p(A, B);
		D[A][B] = 1;
		D[B][A] = 1;
	}
}

void Floydwarshall()
{
	for (int k = 1; k <= N; ++k)
	{
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j <= N; ++j)
			{
				if (i == j || i == k || j == k || D[i][k] == Inf || D[k][j] == Inf)
				{
					continue;
				}

				D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			if (i == j || D[i][j] == Inf)
			{
				continue;
			}

			MD[i] = max(MD[i], D[i][j]);
		}
	}
}

void MakeAnswer()
{
	for (int i = 0; i < M; ++i)
	{
		int A = Lines[i].first;
		int B = Lines[i].second;
		if (Find(A) != Find(B))
		{
			Union(A, B);
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		Answer.insert(Find(i));
	}
}

void Print()
{
	cout << Answer.size() << '\n';
	for (const int Num : Answer)
	{
		cout << Num << '\n';
	}
}

int main()
{
	Initialize();
	Floydwarshall();
	MakeAnswer();
	Print();
}