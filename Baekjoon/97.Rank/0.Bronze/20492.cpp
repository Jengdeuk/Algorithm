#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	cout << N / 100 * 78 << ' ' << N - (N / 100 * 20) / 100 * 22;
}