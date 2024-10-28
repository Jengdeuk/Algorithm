#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, B, C;
	cin >> A >> B >> C;
	if (A + B >= 2 * C)
	{
		cout << A + B - 2 * C;
	}
	else
	{
		cout << A + B;
	}
}