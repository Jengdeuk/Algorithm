#include <iostream>
using namespace std;

int GCD(int A, int B)
{
	int X = max(A, B);
	int Y = min(A, B);
	int Z;
	do
	{
		Z = X % Y;
		X = Y;
		Y = Z;
	} while (Z != 0);

	return X;
}

void Test()
{
	int A, B;
	cin >> A >> B;
	cout << A * B / GCD(A, B) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}