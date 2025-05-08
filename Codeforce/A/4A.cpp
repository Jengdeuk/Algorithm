#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int w;
	cin >> w;
	if (w != 2 && w % 2 == 0)
		cout << "YES";
	else
		cout << "NO";
}