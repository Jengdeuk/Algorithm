#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, A, B;
	cin >> N >> A >> B;
	if (A > B)
	{
		int Temp = A;
		A = B;
		B = Temp;
	}

	int R = 1, T = 2;
	while (true)
	{
		int TA = (A - 1) / T;
		int TB = (B - 1) / T;
		if (TA == TB)
		{
			break;
		}

		T *= 2;
		++R;
	}
	
	cout << R;
}