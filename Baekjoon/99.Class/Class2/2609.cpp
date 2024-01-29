#include <iostream>
using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	int LeftNumber = A;
	int RightNumber = B;
	int Divisor = LeftNumber % RightNumber;
	while (Divisor != 0)
	{
		LeftNumber = RightNumber;
		RightNumber = Divisor;
		Divisor = LeftNumber % RightNumber;
	}
	cout << RightNumber << '\n';

	cout << A * B / RightNumber;
}