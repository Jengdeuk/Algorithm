#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, B;
	cin >> A >> B;

	int Year = 0;
	while (A <= B)
	{
		A *= 3;
		B *= 2;
		Year++;
	}

	cout << Year;
}