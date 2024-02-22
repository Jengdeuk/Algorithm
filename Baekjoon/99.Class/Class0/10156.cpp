#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K, N, M;
	cin >> K >> N >> M;

	int Need = K * N;
	cout << ((Need - M < 0) ? 0 : Need - M);
}