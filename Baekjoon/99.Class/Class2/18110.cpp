#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Scores;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	if (N == 0)
	{
		cout << 0;
		return 0;
	}

	Scores.reserve(N);

	float CutNumber = floor(N * 0.15f + 0.5f);
	for (int i = 0; i < N; ++i)
	{
		int Score;
		cin >> Score;
		Scores.emplace_back(Score);
	}

	sort(Scores.begin(), Scores.end());
	
	float Sum = 0;
	for (int i = CutNumber; i < N - CutNumber; ++i)
	{
		Sum += Scores[i];
	}
	cout << floor(Sum / (N - 2 * CutNumber) + 0.5f);
}