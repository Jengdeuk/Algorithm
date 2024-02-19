#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int X, N;
	cin >> X >> N;

	int Sum = 0;
	for (int i = 0; i < N; ++i)
	{
		int Cost, Num;
		cin >> Cost >> Num;
		Sum += Cost * Num;
	}

	if (Sum == X)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}