#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		string Name;
		int Age, Weight;
		cin >> Name >> Age >> Weight;
		if (Name.compare("#") == 0 && Age == 0 && Weight == 0)
		{
			break;
		}

		cout << Name << ' ';
		if (Age > 17 || Weight >= 80)
		{
			cout << "Senior\n";
		}
		else
		{
			cout << "Junior\n";
		}
	}
}