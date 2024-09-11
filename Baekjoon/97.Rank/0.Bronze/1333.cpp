#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, L, D;
	cin >> N >> L >> D;

	int T = 0;
	int Num = 1;
	bool bWait = false;
	int Song = L;
	int Ring = 0;
	while (true)
	{
		if (!bWait && Song == 0)
		{
			bWait = true;
			Song = 5;
			if (Num == N)
			{
				break;
			}
		}
		else if (bWait && Song == 0)
		{
			bWait = false;
			Song = L;
			++Num;
		}

		if (bWait && Ring == 0)
		{
			break;
		}

		if (Ring == 0)
		{
			Ring = D;
		}

		--Song;
		--Ring;
		++T;
	}

	if (Num == N && Ring > 0)
	{
		T += Ring;
	}

	cout << T;
}