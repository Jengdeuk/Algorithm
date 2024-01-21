#include <iostream>
#include <string>
using namespace std;

int main()
{
	int a = 0, b = 0, c = 0;
	cin >> a;
	cin >> b;
	cin >> c;

	int product = a * b * c;
	string productString = to_string(product);
	for (int i = 0; i <= 9; ++i)
	{
		int count = 0;
		for (int j = 0; j < productString.length(); ++j)
		{
			if (productString[j] - '0' == i)
			{
				++count;
			}
		}
		cout << count << "\n";
	}
}