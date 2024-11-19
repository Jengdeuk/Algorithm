#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int S, T, D;
	cin >> S >> T >> D;
	cout << (D / (S * 2)) * T;
}