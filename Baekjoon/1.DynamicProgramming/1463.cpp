#include <iostream>
#include <algorithm>
using namespace std;

static int minOp[1000001];

int main()
{
	int n;
	cin >> n;

	minOp[2] = minOp[3] = 1;
	for (int i = 4; i <= n; ++i)
	{
		int op3 = 100, op2 = 100, op1 = 100;

		if (i % 3 == 0)
		{
			op3 = min(minOp[i / 3], minOp[i - 1]) + 1;
		}

		if (i % 2 == 0)
		{
			op2 = min(minOp[i / 2], minOp[i - 1]) + 1;
		}

		op1 = minOp[i] = minOp[i - 1] + 1;

		minOp[i] = min(min(op3, op2), op1);
	}

	cout << minOp[n];
}