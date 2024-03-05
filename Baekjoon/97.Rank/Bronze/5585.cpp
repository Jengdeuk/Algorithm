#include <iostream>
using namespace std;

const int M[6] = { 500, 100, 50, 10, 5, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Cost;
	cin >> Cost;

	int Cnt = 0;
	int Money = 1000 - Cost;
	for (int i = 0; i < 6; ++i)
	{
		while (Money >= M[i])
		{
			Money -= M[i];
			++Cnt;
		}
	}

	cout << Cnt;
}