#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, B;
	cin >> A >> B;

	bool bFound = false;
	int C, D;
	for (int i = 0; i <= 1000; ++i)
	{
		C = i;
		D = A - C;
		if (D < 0)
		{
			continue;
		}

		if (abs(C - D) == B)
		{
			bFound = true;
			break;
		}
	}

	if (bFound)
	{
		cout << max(C, D) << ' ' << min(C, D);
	}
	else
	{
		cout << -1;
	}
}