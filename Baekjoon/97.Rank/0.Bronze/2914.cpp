#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, I;
	cin >> A >> I;

	int Num = A * I;
	while (ceil(float(Num - 1) / A) == I)
	{
		--Num;
	}

	cout << Num;
}