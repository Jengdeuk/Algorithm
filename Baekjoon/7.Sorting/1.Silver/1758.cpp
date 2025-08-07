#include <iostream>
#include <algorithm>
using namespace std;

int N, S[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	sort(S, S + N, greater<>());

	long long Sum = 0;
	for (int i = 0; i < N; ++i)
	{
		int Num = S[i] - i;
		if (Num <= 0)
		{
			break;
		}

		Sum += Num;
	}

	cout << Sum;
}