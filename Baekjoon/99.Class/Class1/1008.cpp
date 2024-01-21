#include <iostream>
using namespace std;

int main()
{
	double a, b = 0.0;

	cin >> a >> b;
	cout.precision(12);
	cout << fixed;
	cout << a / b;
}