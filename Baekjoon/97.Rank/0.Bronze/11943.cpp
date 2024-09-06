#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, B, C, D;
	cin >> A >> B >> C >> D;
	cout << min(A + D, B + C);
}