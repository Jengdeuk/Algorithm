#include <iostream>
#include <vector>
#include <list>
#include <cstring>
using namespace std;

int N;
int T[501], R[501], E[501];
bool V[501];
list<int> F[501];

void Test()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> T[i];
		R[T[i]] = i;
		E[i] = 0;
		V[i] = false;
		F[i].clear();
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		if (R[A] < R[B])
		{
			F[B].emplace_back(A);
			++E[A];
		}
		else
		{
			F[A].emplace_back(B);
			++E[B];
		}
	}

	int OE[501];
	memcpy(OE, E, sizeof(OE));

	vector<int> Rank;
	Rank.reserve(500);

	int Loop = 0;
	while (Rank.size() < N && Loop < N)
	{
		for (int i = 1; i <= N; ++i)
		{
			int Team = T[i];
			if (E[Team] == 0 && !V[Team])
			{
				V[Team] = true;
				Rank.emplace_back(Team);
				for (const int& Friend : F[Team])
				{
					--E[Friend];
				}

				break;
			}
		}

		++Loop;
	}

	if (Rank.size() < N)
	{
		cout << "?\n";
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		int Team = Rank[i];

		int Count = 0;
		for (int j = 0; j < i; ++j)
		{
			if (R[Rank[j]] > R[Team])
			{
				++Count;
			}
		}

		if (Count != OE[Team])
		{
			cout << "IMPOSSIBLE\n";
			return;
		}
	}

	for (const int& Team : Rank)
	{
		cout << Team << ' ';
	}
	cout << '\n';
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