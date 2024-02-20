#include <iostream>
using namespace std;

int A, C;

long long BinaryFunction(int B)
{
	if (B == 0)
	{
		return 1;
	}
	else if (B == 1)
	{
		return A % C;
	}

	if (B % 2 == 0)
	{
		return BinaryFunction(B / 2) * BinaryFunction(B / 2) % C;
	}
	else
	{
		return BinaryFunction(B / 2) * BinaryFunction(B / 2 + 1) % C;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int B;
	cin >> A >> B >> C;

	cout << BinaryFunction(B);
}