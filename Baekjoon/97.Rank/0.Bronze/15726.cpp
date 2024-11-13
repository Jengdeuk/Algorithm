#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	double A, B, C;
	cin >> A >> B >> C;
	cout << int(max(A * B / C, A / B * C));
}