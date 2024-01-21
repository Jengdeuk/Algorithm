#include <iostream>
#include <string>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int score = 0;

		string quizResults;
		cin >> quizResults;

		int continuityScore = 0;
		for (const char& grading : quizResults)
		{
			if (grading == 'O')
			{
				++continuityScore;
			}
			else
			{
				continuityScore = 0;
			}

			score += continuityScore;
		}

		cout << score << "\n";
	}
}