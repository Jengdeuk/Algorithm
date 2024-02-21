#include <iostream>
using namespace std;

typedef pair<double, double> Vec2;

Vec2 Vertex[10000];

double GetTriangle(const Vec2& A, const Vec2& B, const Vec2& C)
{
	Vec2 AB = Vec2(B.first - A.first, B.second - A.second);
	Vec2 AC = Vec2(C.first - A.first, C.second - A.second);

	return (AB.first * AC.second - AB.second * AC.first) / 2.0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	double Sum = 0.0;

	int N;
	cin >> N;
	cin >> Vertex[0].first >> Vertex[0].second;
	for (int i = 1; i < N; ++i)
	{
		cin >> Vertex[i].first >> Vertex[i].second;
		Sum += GetTriangle(Vertex[0], Vertex[i - 1], Vertex[i]);
	}
	
	cout << fixed;
	cout.precision(1);
	cout << abs(Sum);
}