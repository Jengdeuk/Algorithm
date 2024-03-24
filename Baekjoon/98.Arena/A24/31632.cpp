#include <iostream>
#include <string>
using namespace std;

const char GODChar[3] = { 'G', 'O', 'D' };

void Test()
{
	int N;
	cin >> N;

	string Betting, Result;
	cin >> Betting >> Result;

	bool GOD[3] = {};
	for (int i = 0; i < N; ++i)
	{
		if (GOD[0] && GOD[1] && GOD[2])
		{
			break;
		}

		for (int j = 0; j < 3; ++j)
		{
			if (Betting[i] == GODChar[j])
			{
				GOD[j] = true;
			}
		}
	}

	bool WDL[3] = {};
	for (int i = 0; i < N; ++i)
	{
		if (Result[i] == 'W')
		{
			WDL[0] = true;
		}

		if (Result[i] == 'D')
		{
			WDL[1] = true;
		}

		if (Result[i] == 'L')
		{
			WDL[2] = true;
		}
	}

	int Cnt = 0;
	for (int i = 0; i < 3; ++i)
	{
		if (GOD[i])
		{
			++Cnt;
		}
	}

	if ((WDL[1] && WDL[0])
		|| (WDL[1] && WDL[2])
		|| (WDL[0] && !WDL[2])
		|| (!WDL[0] && WDL[2]))
	{
		cout << "NO\n";
		return;
	}

	// Draw
	if (WDL[1])
	{
		cout << "YES\n";

		if (Cnt == 0)
		{
			for (int i = 0; i < N; ++i)
			{
				cout << 'G';
			}

			cout << '\n';
			return;
		}

		char DC = '-';
		for (int i = 0; i < 3; ++i)
		{
			if (((Cnt == 1 || Cnt == 3) && GOD[i])
				|| ((Cnt == 2) && !GOD[i]))
			{
				DC = GODChar[i];
				break;
			}
		}

		for (int i = 0; i < N; ++i)
		{
			if (Betting[i] != '?')
			{
				cout << Betting[i];
				continue;
			}

			cout << DC;
		}

		cout << '\n';
		return;
	}

	// Win & Lose
	if (Cnt == 0)
	{
		cout << "YES\n";

		for (int i = 0; i < N; ++i)
		{
			if (Result[i] == 'W')
			{
				cout << 'G';
			}
			else
			{
				cout << 'O';
			}
		}

		cout << '\n';
		return;
	}

	char WC = '-', LC = '-';
	for (int i = 0; i < N; ++i)
	{
		if (Betting[i] == '?')
		{
			continue;
		}

		for (int j = 0; j < 3; ++j)
		{
			if (Betting[i] != GODChar[j])
			{
				continue;
			}

			if (Result[i] == 'W')
			{
				WC = GODChar[j];
				LC = GODChar[(j + 1) % 3];
			}
			else
			{
				WC = GODChar[(j - 1 < 0) ? 2 : j - 1];
				LC = GODChar[j];
			}

			i = N;
			break;
		}
	}

	for (int i = 0; i < N; ++i)
	{
		if (Betting[i] == '?')
		{
			continue;
		}
		
		if ((Result[i] == 'W' && WC != Betting[i])
			|| (Result[i] == 'L' && LC != Betting[i]))
		{
			cout << "NO\n";
			return;
		}
	}

	cout << "YES\n";

	for (int i = 0; i < N; ++i)
	{
		if (Betting[i] != '?')
		{
			cout << Betting[i];
			continue;
		}

		if (Result[i] == 'W')
		{
			cout << WC;
		}
		else
		{
			cout << LC;
		}
	}

	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}