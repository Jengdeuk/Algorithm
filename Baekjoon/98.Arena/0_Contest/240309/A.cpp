#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, M, N;
	cin >> A >> M >> N;

	cout << fixed;
	cout.precision(7);
	cout << min(double(min(M, N)) / A * 2, double(max(M, N)));
}