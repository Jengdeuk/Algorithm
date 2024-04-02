#include <iostream>
using namespace std;

int Sum[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		int Num;
		cin >> Num;
		Sum[i] = Sum[i - 1] + Num;
	}

	int Max = -100000000;
	for (int i = 0; i + K <= N; ++i)
	{
		int S = Sum[i + K] - Sum[i];
		Max = max(Max, S);
	}

	cout << Max;
}