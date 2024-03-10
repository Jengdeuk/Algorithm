#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Cnt = 0;
	bool bWhite = true;
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			char Ch;
			cin.get(Ch);
			if (bWhite && Ch == 'F')
			{
				++Cnt;
			}

			bWhite = !bWhite;
		}
		bWhite = !bWhite;
		cin.ignore();
	}

	cout << Cnt;
}