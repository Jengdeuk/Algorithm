#include <iostream>
#include <algorithm>
using namespace std;

int Value[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Value[i];
	}

	sort(Value, Value + N);

	int A = 1000000000, B = 1000000000;
	int Sol = A + B;
	for (int i = 0; i < N; ++i)
	{
		int S = 0, E = N - 1;
		while (S <= E)
		{
			int j = (S + E) / 2;
			if (j == i)
			{
				if (Value[i] > 0)
				{
					E = j - 1;
				}
				else
				{
					S = j + 1;
				}

				continue;
			}

			int Sum = Value[i] + Value[j];

			if (Sum == 0)
			{
				cout << min(Value[i], Value[j]) << ' ' << max(Value[i], Value[j]);
				return 0;
			}
			else if (Sum > 0)
			{
				E = j - 1;
			}
			else
			{
				S = j + 1;
			}

			if (abs(Sum) < Sol)
			{
				Sol = abs(Sum);
				A = Value[i];
				B = Value[j];
			}
		}
	}

	cout << min(A, B) << ' ' << max(A, B);
}