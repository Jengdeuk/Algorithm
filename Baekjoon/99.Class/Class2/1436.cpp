#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int Cnt = 1;
	int Number = 666;
	while (Cnt != N)
	{
		++Cnt;

		bool bFound = false;
		while (!bFound)
		{
			++Number;

			string Name = to_string(Number);
			for (int i = 0; i < Name.length() - 2; ++i)
			{
				if (Name[i] == '6'
					&& Name[i + 1] == '6'
					&& Name[i + 2] == '6')
				{
					bFound = true;
					break;
				}
			}
		}
	}

	cout << Number;
}