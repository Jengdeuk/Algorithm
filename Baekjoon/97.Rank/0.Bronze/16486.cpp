#include <iostream>
using namespace std;

const double Pi = 3.141592;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	double D1, D2;
	cin >> D1 >> D2;

	double Answer = 2 * D1 + 2 * Pi * D2;
	cout << fixed;
	cout.precision(6);
	cout << Answer;
}