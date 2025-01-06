#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, W, H, L;
	cin >> N >> W >> H >> L;

	int Max = (W / L) * (H / L);
	cout << min(N, Max);
}