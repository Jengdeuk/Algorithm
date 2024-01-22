#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int weight = 0;
	int i = 0, j = 0, result = -1;
	bool finished = false;
	while (!finished)
	{
		while (true)
		{
			weight = 5 * j + 3 * i;
			if (weight == n)
			{
				finished = true;
				result = i + j;
				break;
			}
			else if (weight > n)
			{
				j = 0;
				break;
			}

			++j;
		}

		++i;
		if (5 * j + 3 * i > n)
		{
			finished = true;
		}
	}

	cout << result;
}