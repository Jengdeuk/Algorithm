#include <iostream>
#include <algorithm>
using namespace std;

void Test()
{
	int Food[5];
	for (int i = 0; i < 5; ++i)
	{
		cin >> Food[i];
	}

	Food[0] /= 0.5;
	Food[1] /= 0.5;
	Food[2] /= 0.25;
	Food[3] /= 0.0625;
	Food[4] /= 0.5625;

	sort(Food, Food + 5);
	int Max1 = Food[0];

	for (int i = 0; i < 4; ++i)
	{
		cin >> Food[i];
	}

	Food[0] /= 1;
	Food[1] /= 30;
	Food[2] /= 25;
	Food[3] /= 10;

	int Max2 = 0;
	for (int i = 0; i < 4; ++i)
	{
		Max2 += Food[i];
	}

	cout << min(Max1, Max2) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}