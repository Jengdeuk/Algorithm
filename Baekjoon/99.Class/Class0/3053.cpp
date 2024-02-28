#include <iostream>
using namespace std;

const double Pi = 3.14159265358979323846;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	double R;
	cin >> R;

	cout << fixed;
	cout.precision(6);
	cout << R * R * Pi << '\n';
	cout << 2 * R * R << '\n';
}