#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string A, B;
	cin >> A >> B;
	
	string AA = A, BB = B;
	for (int i = 0; i < AA.size(); ++i)
	{
		if (AA[i] == '5')
		{
			AA[i] = '6';
		}
	}

	for (int i = 0; i < BB.size(); ++i)
	{
		if (BB[i] == '5')
		{
			BB[i] = '6';
		}
	}

	int Max = stoi(AA) + stoi(BB);

	for (int i = 0; i < AA.size(); ++i)
	{
		if (AA[i] == '6')
		{
			AA[i] = '5';
		}
	}

	for (int i = 0; i < BB.size(); ++i)
	{
		if (BB[i] == '6')
		{
			BB[i] = '5';
		}
	}

	int Min = stoi(AA) + stoi(BB);

	cout << Min << ' ' << Max;
}