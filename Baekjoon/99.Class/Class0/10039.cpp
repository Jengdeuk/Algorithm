#include <iostream>
using namespace std;

int Score[5];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int Sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		cin >> Score[i];
		if (Score[i] < 40)
		{
			Sum += 40;
		}
		else
		{
			Sum += Score[i];
		}
	}
	cout << Sum / 5;
}