#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> pp;

typedef vector<int> vec;
typedef pair<int, vec> pv;

int N, M;
int S[8], O[8];
pp Op[10];

map<vec, int> D;

vec NewVec(vec V, int L, int R)
{
	int Temp = V[L];
	V[L] = V[R];
	V[R] = Temp;
	return V;
}

void Dijkstra()
{
	vec V;
	V.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		V.emplace_back(S[i]);
	}
	D[V] = 0;

	priority_queue<pv, vector<pv>, greater<pv>> PQ;
	PQ.emplace(0, V);
	while (!PQ.empty())
	{
		vec CV = PQ.top().second;
		int CW = PQ.top().first;
		PQ.pop();

		if (CW > D[CV])
		{
			continue;
		}

		for (int i = 0; i < M; ++i)
		{
			int L = Op[i].second.first;
			int R = Op[i].second.second;
			int W = Op[i].first;

			vec NV = NewVec(CV, L - 1, R - 1);
			int NW = CW + W;
			if (D.find(NV) == D.end() || NW < D[NV])
			{
				D[NV] = NW;
				PQ.emplace(NW, NV);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
		O[i] = S[i];
	}

	sort(O, O + N);

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int L, R, C;
		cin >> Op[i].second.first >> Op[i].second.second >> Op[i].first;
	}

	Dijkstra();

	vec V;
	V.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		V.emplace_back(O[i]);
	}

	if (D.find(V) != D.end())
	{
		cout << D[V];
	}
	else
	{
		cout << -1;
	}
}