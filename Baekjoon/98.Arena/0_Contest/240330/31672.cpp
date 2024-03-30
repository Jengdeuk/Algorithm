#include <iostream>
#include <string>
using namespace std;

int N;
bool S[11][11];
bool Suspect[11];

bool Detect(int Num)
{
	bool bThief = true;
	for (int i = 1; i <= N; ++i)
	{
		if (i != Num && !S[i][Num])
		{
			bThief = false;
			break;
		}
	}

	if (bThief && !S[Num][Num])
	{
		return true;
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string Str;
	getline(cin, Str);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int M;
		cin >> M;
		for (int j = 0; j < M; ++j)
		{
			int Num;
			cin >> Num;
			S[i][Num] = true;
		}

		bool bDontSwitch = false;
		cin >> bDontSwitch;
		if (!bDontSwitch)
		{
			for (int j = 1; j <= N; ++j)
			{
				S[i][j] = !S[i][j];
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		Suspect[i] = Detect(i);
	}

	bool bFound = false;
	for (int i = 1; i <= N; ++i)
	{
		if (Suspect[i])
		{
			bFound = true;
			break;
		}
	}

	if (bFound)
	{
		for (int i = 1; i <= N; ++i)
		{
			if (Suspect[i])
			{
				cout << i << ' ';
			}
		}
	}
	else
	{
		cout << "swi";
	}
}