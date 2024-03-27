#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string N8;
	cin >> N8;
	if (N8.compare("0") == 0)
	{
		cout << N8;
		return 0;
	}

	string N2;
	for (int i = 0; i < N8.size(); ++i)
	{
		int Num = N8[i] - '0';

		string Num2;
		while (Num > 0)
		{
			Num2.push_back(Num % 2 + '0');
			Num /= 2;
		}

		for (int i = 0; i < 3 - Num2.size(); ++i)
		{
			N2.push_back('0');
		}

		for (int i = Num2.size() - 1; i >= 0; --i)
		{
			N2.push_back(Num2[i]);
		}
	}

	bool bFind = false;
	for (int i = 0; i < N2.size(); ++i)
	{
		if (!bFind && N2[i] == '0')
		{
			continue;
		}

		bFind = true;
		cout << N2[i];
	}
}