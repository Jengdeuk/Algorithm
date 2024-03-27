#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	float SumValue = 0.f;
	float SumScore = 0.f;
	for (int i = 0; i < 20; ++i)
	{
		string Title, Grade;
		float Value;
		cin >> Title >> Value >> Grade;

		char G1 = Grade[0], G2;
		if (G1 != 'P' && G1 != 'F')
		{
			G2 = Grade[1];
		}

		float Score = 0.f;
		switch (G1)
		{
		case 'A':
			if (G2 == '+') Score = 4.5f;
			else Score = 4.f;
			break;

		case 'B':
			if (G2 == '+') Score = 3.5f;
			else Score = 3.f;
			break;

		case 'C':
			if (G2 == '+') Score = 2.5f;
			else Score = 2.f;
			break;

		case 'D':
			if (G2 == '+') Score = 1.5f;
			else Score = 1.f;
			break;
		}

		if (G1 != 'P')
		{
			SumValue += Value;
			SumScore += Value * Score;
		}
	}

	cout << fixed;
	cout.precision(6);
	cout << SumScore / SumValue;
}