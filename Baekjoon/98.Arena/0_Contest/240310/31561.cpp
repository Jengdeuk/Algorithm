#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int M;
	cin >> M;
	
	cout << fixed;
	cout.precision(1);

	if (M <= 30)
	{
		cout << double(M) / 2;
	}
	else
	{
		cout << 15.0 + double(M - 30) * 3.0 / 2.0;
	}
}