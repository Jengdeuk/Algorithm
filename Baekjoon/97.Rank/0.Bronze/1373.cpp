#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string N2;
	cin >> N2;
	if (N2.compare("0") == 0)
	{
		cout << N2;
		return 0;
	}

	string N8;
	for (int i = N2.size() - 1; i >= 0; i -= 3)
	{
		int Num = 0;
		for (int j = 0; j < 3; ++j)
		{
			if (i - j < 0)
			{
				break;
			}

			Num += (N2[i - j] - '0') * pow(2, j);
		}

		N8.push_back(Num + '0');
	}

	for (int i = N8.size() - 1; i >= 0; --i)
	{
		cout << N8[i];
	}
}