#include <iostream>
using namespace std;

const int Num = 5;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int Day;
	cin >> Day;

	int Count = 0;
	for (int i = 0; i < Num; ++i)
	{
		int Car;
		cin >> Car;

		if (Car == Day)
		{
			++Count;
		}
	}

	cout << Count;
}