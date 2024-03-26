#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	long long A, B;
	cin >> A >> B;
	cout << (A + B) * (A - B);
}