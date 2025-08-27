#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	int Sum = 0;
	for (int i = 1; i <= K; ++i)
	{
		Sum += i;
	}
	N -= Sum;

	if (N >= 0)
	{
		if (N % K == 0)
		{
			cout << K - 1;
		}
		else
		{
			cout << K;
		}
	}
	else
	{
		cout << -1;
	}
}