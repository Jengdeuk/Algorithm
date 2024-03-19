#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, B, C, D, E, F;
	cin >> A >> B >> C >> D >> E >> F;

	int X = (C * E - B * F) / (A * E - B * D);
	int Y = (C * D - A * F) / (B * D - A * E);
	cout << X << ' ' << Y;
}