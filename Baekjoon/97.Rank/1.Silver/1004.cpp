#include <iostream>
using namespace std;

typedef pair<int, int> pos;

bool InPlanet(pos Position, pos PlanetPos, int Radius)
{
	int X = Position.first;
	int Y = Position.second;
	int PX = PlanetPos.first;
	int PY = PlanetPos.second;

	return ((PX - X) * (PX - X) + (PY - Y) * (PY - Y) < Radius * Radius);
}

void Test()
{
	pos S, E;
	cin >> S.first >> S.second >> E.first >> E.second;

	int N;
	cin >> N;

	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		pos PlanetPos;
		cin >> PlanetPos.first >> PlanetPos.second;
		int Radius;
		cin >> Radius;

		if (InPlanet(S, PlanetPos, Radius)
			&& !InPlanet(E, PlanetPos, Radius))
		{
			++Cnt;
		}
		else if (!InPlanet(S, PlanetPos, Radius)
				&& InPlanet(E, PlanetPos, Radius))
		{
			++Cnt;
		}
	}

	cout << Cnt << '\n';
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