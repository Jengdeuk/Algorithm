#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<float> Scores;

int main()
{
	int N;
	cin >> N;

	Scores.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Score;
		cin >> Score;
		Scores.emplace_back(Score);
	}

	int MaxScore = *max_element(Scores.begin(), Scores.end());
	for (float& Score : Scores)
	{
		Score /= MaxScore;
		Score *= 100.f;
	}

	float Sum = 0.f;
	for (const float& Score : Scores)
	{
		Sum += Score;
	}

	float Average = Sum / N;
	cout << Average;
}