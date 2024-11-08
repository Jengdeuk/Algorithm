#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A1, A0, C, N0;
	cin >> A1 >> A0 >> C >> N0;
	cout << (A1 <= C && A0 <= (C - A1) * N0);
}