#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int A = N % 8;
	if (A == 0)
	{
		A = 2;
	}
	else if (A > 5)
	{
		A = 10 - A;
	}

	cout << A;
}