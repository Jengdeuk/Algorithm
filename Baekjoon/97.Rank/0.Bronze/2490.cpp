#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 3; ++i)
	{
		int Sum = 0;
		for (int j = 0; j < 4; ++j)
		{
			int Num;
			cin >> Num;
			Sum += Num;
		}

		switch (4 - Sum)
		{
		case 0:
			cout << "E\n";
			break;

		case 1:
			cout << "A\n";
			break;

		case 2:
			cout << "B\n";
			break;

		case 3:
			cout << "C\n";
			break;

		case 4:
			cout << "D\n";
			break;
		}
	}
}