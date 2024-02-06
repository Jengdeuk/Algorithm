#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> Vertices;

bool Compare(const pair<int, int>& Left, const pair<int, int>& Right)
{
	return (Left.first == Right.first) ? Left.second < Right.second : Left.first < Right.first;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	Vertices.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int X, Y;
		cin >> X >> Y;
		Vertices.emplace_back(X, Y);
	}

	sort(Vertices.begin(), Vertices.end(), Compare);

	for (const pair<int, int>& Vertice : Vertices)
	{
		cout << Vertice.first << ' ' << Vertice.second << '\n';
	}
}