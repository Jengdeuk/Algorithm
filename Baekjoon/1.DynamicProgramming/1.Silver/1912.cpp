#include <iostream>
#include <vector>
using namespace std;

vector<int> DP;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	DP.reserve(N);

	int Num;
	cin >> Num;
	DP.emplace_back(Num);

	int Max = Num;
	for (int i = 1; i < N; ++i)
	{
		cin >> Num;
		Num = max(Num, DP[i - 1] + Num);
		DP.emplace_back(Num);

		Max = max(Max, Num);
	}

	cout << Max;
}