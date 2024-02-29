#include <iostream>
using namespace std;

int Solution[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Solution[i];
	}

	int ResultSum = 2000000000;
	int ResultLeft = 0;
	int ResultRight = 0;

	int L = 0;
	int R = N - 1;
	while (L < R)
	{
		int Left = Solution[L];
		int Right = Solution[R];
		int Sum = Left + Right;

		if (abs(Sum) < abs(ResultSum))
		{
			ResultSum = Sum;
			ResultLeft = Left;
			ResultRight = Right;
		}

		if (Sum == 0)
		{
			break;
		}
		else if (Sum < 0)
		{
			++L;
		}
		else
		{
			--R;
		}
	}

	cout << ResultLeft << ' ' << ResultRight;
}