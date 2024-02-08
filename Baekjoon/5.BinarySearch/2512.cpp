#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Weights;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	Weights.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Weight;
		cin >> Weight;
		Weights.emplace_back(Weight);
	}

	sort(Weights.begin(), Weights.end());

	int M;
	cin >> M;

	int Solution = 0;
	int Left = 0;
	int Right = M;
	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;
		
		int Count = 0;
		int MaxWeight = 0;
		for (const int& Weight : Weights)
		{
			if (Weight < Mid)
			{
				Count += Weight;
				MaxWeight = max(MaxWeight, Weight);
			}
			else
			{
				Count += Mid;
				MaxWeight = max(MaxWeight, Mid);
			}

			if (Count > M)
			{
				break;
			}
		}

		if (Count <= M)
		{
			Solution = MaxWeight;
			Left = Mid + 1;
		}
		else
		{
			Right = Mid - 1;
		}
	}

	cout << Solution;
}