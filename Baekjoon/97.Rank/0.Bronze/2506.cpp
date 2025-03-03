#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int score = 0, grade = 0;
	for (int i = 0; i < n; ++i)
	{
		bool bCorrect;
		cin >> bCorrect;
		if (bCorrect)
			score += ++grade;
		else
			grade = 0;
	}

	cout << score;
}