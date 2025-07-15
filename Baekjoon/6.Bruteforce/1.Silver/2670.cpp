#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	double DP = 1, MDP = 0;
	for (int i = 0; i < N; ++i)
	{
		double Num;
		cin >> Num;
		if (i == 0)
		{
			DP = Num;
		}
		else
		{
			DP = max(DP * Num, Num);
		}

		MDP = max(MDP, DP);
	}

	cout.precision(3);
	cout << fixed << MDP;
}