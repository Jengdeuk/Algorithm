#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int L, P;
	cin >> L >> P;

	for (int i = 0; i < 5; ++i)
	{
		int Number;
		cin >> Number;
		cout << Number - L * P << ' ';
	}
}