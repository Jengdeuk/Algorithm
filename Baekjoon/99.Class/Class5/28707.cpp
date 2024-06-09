#include <iostream>
#include <list>
#include <algorithm>
#include <unordered_map>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> pp;

int N, M;
int S[8], O[8];
pp Op[10];

unordered_map<int[], int> D;

bool Check()
{
	for (int i = 0; i < N; ++i)
	{
		if (S[i] != O[i])
		{
			return false;
		}
	}

	return true;
}

void Dijkstra()
{

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
}