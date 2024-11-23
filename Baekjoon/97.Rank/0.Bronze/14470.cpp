#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;

	int T = 0;
	bool bFreeze = false;
	while (A < B)
	{
		if (A < 0)
		{
			bFreeze = true;
			T += A * -C;
			A = 0;
		}
		else if (bFreeze && A == 0)
		{
			bFreeze = false;
			T += D;
		}
		else
		{
			T += (B - A) * E;
			A = B;
		}
	}

	cout << T;
}