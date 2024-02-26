#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int L, A, B, C, D;
	cin >> L >> A >> B >> C >> D;

	int Ko = ceil(float(A) / C);
	int Ma = ceil(float(B) / D);

	cout << L - max(Ko, Ma);
}