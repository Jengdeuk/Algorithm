#include <iostream>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;

typedef pair<double, double> p;

int N;
p P[20];

int Plus, Minus;
p Vector;
double Min;

double Norm(const p& Vec)
{
	return sqrt(Vec.first * Vec.first + Vec.second * Vec.second);
}

void Btf(int Cur)
{
	if (Cur == N)
	{
		Min = min(Min, Norm(Vector));
		return;
	}

	if (Plus < N / 2)
	{
		++Plus;
		Vector.first += P[Cur].first;
		Vector.second += P[Cur].second;
		Btf(Cur + 1);
		Vector.first -= P[Cur].first;
		Vector.second -= P[Cur].second;
		--Plus;
	}

	if (Minus < N / 2)
	{
		++Minus;
		Vector.first -= P[Cur].first;
		Vector.second -= P[Cur].second;
		Btf(Cur + 1);
		Vector.first += P[Cur].first;
		Vector.second += P[Cur].second;
		--Minus;
	}
}

void Test()
{
	Plus = 0, Minus = 0;
	Min = LLONG_MAX;
	Vector = p(0, 0);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> P[i].first >> P[i].second;
	}

	Btf(0);

	cout << fixed;
	cout.precision(12);
	cout << Min << '\n';
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