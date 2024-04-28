#include <iostream>
#include <cstring>
using namespace std;

int N, Sum;
int Num[500000], Temp[500000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		int A;
		cin >> A;
		if (A == 1)
		{
			cin >> Num[N];
			Sum += Num[N];
			++N;
		}
		else
		{
			int SumL = 0, SumR = 0;

			int j = 0;
			for (int i = N / 2; i < N; ++i)
			{
				SumR += Num[i];
				Temp[j] = Num[i];
				++j;
			}

			SumL = Sum - SumR;
			if (SumL > SumR)
			{
				cout << SumR << '\n';
				Sum = SumL;
				N /= 2;
			}
			else
			{
				cout << SumL << '\n';
				Sum = SumR;
				N = N / 2 + (N % 2);
				memcpy(Num, Temp, sizeof(Num));
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		cout << Num[i] << ' ';
	}
}