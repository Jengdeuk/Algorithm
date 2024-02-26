#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, B, C, D, X, Y, Z, W;
	cin >> A >> B >> C >> D >> X >> Y >> Z >> W;
	cout << max(A + B + C + D, X + Y + Z + W);
}