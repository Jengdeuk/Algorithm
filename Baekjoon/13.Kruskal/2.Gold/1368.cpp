#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> edge;

int N, R[301];
vector<edge> E;

int Find(int Cur)
{
	if (Cur == R[Cur])
	{
		return Cur;
	}

	return R[Cur] = Find(R[Cur]);
}

void Union(int A, int B)
{
	R[Find(A)] = Find(B);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int Cst;
		cin >> Cst;
		E.emplace_back(Cst, p(0, i));
		R[i] = i;
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			int Cst;
			cin >> Cst;
			if (j == i)
			{
				continue;
			}

			E.emplace_back(Cst, p(i, j));
		}
	}

	sort(E.begin(), E.end());

	int EN = E.size();
	vector<bool> V(EN, false);

	int Link = 0, Sum = 0;
	while (Link < N)
	{
		for (int i = 0; i < EN; ++i)
		{
			if (V[i])
			{
				continue;
			}

			int A = E[i].second.first;
			int B = E[i].second.second;
			if (Find(A) == Find(B))
			{
				continue;
			}

			V[i] = true;
			Sum += E[i].first;
			Union(A, B);
			Link++;
			break;
		}
	}

	cout << Sum;
}