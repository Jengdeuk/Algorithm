#include <iostream>
using namespace std;

int Win[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	Win[1] = 1;
	Win[2] = 2;
	Win[3] = 1;
	for (int i = 1; i + 3 <= N; ++i)
	{
		if (Win[i + 1] == 0)
		{
			Win[i + 1] = (Win[i] == 1) ? 2 : 1;
		}

		if (Win[i + 3] == 0)
		{
			Win[i + 3] = (Win[i] == 1) ? 2 : 1;
		}
	}

	cout << ((Win[N] == 1) ? "SK" : "CY");
}