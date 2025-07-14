#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	double A, B, M;
	cin >> A >> B >> M;

	double Sum = 0;
	for (int i = M - 1; i >= 0; --i)
	{
		int Num;
		cin >> Num;
		Sum += Num * pow(A, i);
	}

	double N = 25;
	while (N > 0 && pow(B, N) > Sum)
	{
		N--;
	}

	for (int i = N; i >= 0; --i)
	{
		double Num = B - 1;
		while (Num > 0 && Num * pow(B, i) > Sum)
		{
			Num--;
		}
		Sum -= Num * pow(B, i);
		cout << Num << ' ';
	}
}