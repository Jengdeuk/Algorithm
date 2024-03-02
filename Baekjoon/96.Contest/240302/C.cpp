#include <iostream>
#include <string>
using namespace std;

string Name[500];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Name[i];
	}

	for (int r = 0; r < 2; ++r)
	{
		for (int i = 0; i < N; ++i)
		{
			cout << "? " << Name[i] << '\n' << flush;

			int Answer;
			cin >> Answer;

			if (Answer == 1)
			{
				cout << "! " << Name[i] << flush;
				return 0;
			}
		}
	}
}