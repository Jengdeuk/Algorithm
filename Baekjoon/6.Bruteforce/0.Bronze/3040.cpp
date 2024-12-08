#include <iostream>
using namespace std;

bool A[9];
int S[9];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Sum = 0;
	for (int i = 0; i < 9; ++i)
	{
		cin >> S[i];
		Sum += S[i];
	}

	for (int i = 0; i < 9; ++i)
	{
		for (int j = i + 1; j < 9; ++j)
		{
			if (Sum - S[i] - S[j] == 100)
			{
				A[i] = true;
				A[j] = true;
				i = 10;
				j = 10;
				break;
			}
		}
	}

	for (int i = 0; i < 9; ++i)
	{
		if (!A[i])
		{
			cout << S[i] << '\n';
		}
	}
}