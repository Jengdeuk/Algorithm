#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	const int size = 9;
	for (int i = 1; i <= size; ++i)
	{
		cout << n << " * " << i << " = " << n * i << "\n";
	}
}