#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int l;
	cin >> l;
	if (l % 5 == 0)
		cout << l / 5;
	else
		cout << l / 5 + 1;
}