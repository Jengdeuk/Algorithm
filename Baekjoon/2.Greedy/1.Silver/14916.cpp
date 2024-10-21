#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int A = N / 5;
	N -= A * 5;

	int B = 0;
	if (A == 0 && N % 2 == 1)
	{
		A = -1;
	}
	else if (N % 2 == 0)
	{
		B = N / 2;
	}
	else
	{
		N += 5;
		--A;
		B = N / 2;
	}
	
	cout << A + B;
}