#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 3; ++i)
	{
		int SH, SM, SS, EH, EM, ES;
		cin >> SH >> SM >> SS >> EH >> EM >> ES;

		int H, M, S;
		if (SS <= ES)
		{
			S = ES - SS;
		}
		else
		{
			S = ES + 60 - SS;
			if (EM > 0)
			{
				--EM;
			}
			else
			{
				EM = 59;
				--EH;
			}
		}

		if (SM <= EM)
		{
			M = EM - SM;
		}
		else
		{
			M = EM + 60 - SM;
			--EH;
		}

		H = EH - SH;

		cout << H << ' ' << M << ' ' << S << '\n';
	}
}