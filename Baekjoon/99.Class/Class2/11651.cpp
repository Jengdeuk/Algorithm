#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

vector<p> Coords;

bool Compare(const p& Left, const p& Right)
{
	return (Left.second == Right.second) ? Left.first < Right.first : Left.second < Right.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	Coords.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int X, Y;
		cin >> X >> Y;
		Coords.emplace_back(X, Y);
	}

	sort(Coords.begin(), Coords.end(), Compare);

	for (const p& Coord : Coords)
	{
		cout << Coord.first << ' ' << Coord.second << '\n';
	}
}