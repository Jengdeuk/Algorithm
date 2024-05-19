#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	float D, H, W;
	cin >> D >> H >> W;

	float D2 = sqrt(H * H + W * W);
	cout << int(D / D2 * H) << ' ' << int(D / D2 * W);
}