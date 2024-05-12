#include <iostream>
using namespace std;

int A[2000], B[2000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int X = 0, Y = 0, Cnt = 0;

	int End;
	if (N % 3 == 1)
	{
		End = 2;
	}
	else
	{
		End = 1;
	}

	for (int i = N; i >= End; --i)
	{
		if (Cnt == 0)
		{
			B[Y] = i;
			++Y;
		}
		else
		{
			A[X] = i;
			++X;
		}

		Cnt = (Cnt + 1 > 2 ? 0 : Cnt + 1);
	}

	cout << X << '\n';
	for (int i = X - 1; i >= 0; --i)
	{
		cout << A[i] << ' ';
	}
	cout << '\n';

	cout << Y << '\n';
	for (int i = Y - 1; i >= 0; --i)
	{
		cout << B[i] << ' ';
	}
}