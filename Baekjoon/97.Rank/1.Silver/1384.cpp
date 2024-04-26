#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int Group, N;
string Name[20];
bool BadText[20][19];

void Test()
{
	memset(BadText, false, sizeof(BadText));

	for (int i = 0; i < N; ++i)
	{
		cin >> Name[i];

		for (int j = 0; j < N - 1; ++j)
		{
			char ch;
			cin >> ch;
			if (ch == 'N')
			{
				BadText[i][j] = true;
			}
		}
	}

	cout << "Group " << Group << '\n';

	bool NoBody = true;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N - 1; ++j)
		{
			if (BadText[i][j])
			{
				NoBody = false;

				int BadChildIdx = i + (N - 1 - j);
				if (BadChildIdx >= N)
				{
					BadChildIdx -= N;
				}

				cout << Name[BadChildIdx] << " was nasty about " << Name[i] << '\n';
			}
		}
	}

	if (NoBody)
	{
		cout << "Nobody was nasty\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Group = 1;
	while (true)
	{
		cin >> N;
		if (N == 0)
		{
			break;
		}

		Test();
		++Group;

		cout << '\n';
	}
}