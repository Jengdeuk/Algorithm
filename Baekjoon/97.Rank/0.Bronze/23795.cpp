#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Sum = 0;
	while (true)
	{
		int Num;
		cin >> Num;
		if (Num == -1)
		{
			break;
		}

		Sum += Num;
	}
	
	cout << Sum;
}