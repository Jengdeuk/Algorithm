#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long long> Numbers;

void Init(int N)
{
	Numbers.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Number;
		cin >> Number;
		Numbers.emplace_back(Number);
	}

	sort(Numbers.begin(), Numbers.end());
}

void BinarySearch(int N, int& SolA, int& SolB, int& SolC)
{
	long long Sol = 3000000000;
	SolA = Numbers[0];
	SolB = Numbers[1];
	SolC = Numbers[2];

	for (int A = 0; A < N - 2; ++A)
	{
		int B = A + 1;
		int C = N - 1;

		while (B < C)
		{
			long long Sum = Numbers[A] + Numbers[B] + Numbers[C];

			if (Sum == 0)
			{
				SolA = Numbers[A];
				SolB = Numbers[B];
				SolC = Numbers[C];
				return;
			}

			if (abs(Sum) < abs(Sol))
			{
				Sol = Sum;
				SolA = Numbers[A];
				SolB = Numbers[B];
				SolC = Numbers[C];
			}

			if (Sum > 0) --C;
			else ++B;
		}
	}
}

void Print(int A, int B, int C)
{
	vector<int> Solution(3);

	Solution[0] = A;
	Solution[1] = B;
	Solution[2] = C;

	sort(Solution.begin(), Solution.end());

	for (const int& Num : Solution)
	{
		cout << Num << ' ';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	Init(N);

	int A, B, C;
	BinarySearch(N, A, B, C);
	Print(A, B, C);
}