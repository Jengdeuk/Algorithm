#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int X, Y, W, H;
	cin >> X >> Y >> W >> H;

	vector<int> Distance(4, 10000);
	Distance[0] = X;
	Distance[1] = H - Y;
	Distance[2] = W - X;
	Distance[3] = Y;

	cout << *min_element(Distance.begin(), Distance.end());
}