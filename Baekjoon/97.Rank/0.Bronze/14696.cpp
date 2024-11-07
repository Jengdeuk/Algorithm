#include <iostream>
using namespace std;

void Test()
{
	int N;

	cin >> N;
	int A[5] = {};
	for (int i = 0; i < N; ++i)
	{
		int Card;
		cin >> Card;
		++A[Card];
	}

	cin >> N;
	int B[5] = {};
	for (int i = 0; i < N; ++i)
	{
		int Card;
		cin >> Card;
		++B[Card];
	}

	for (int i = 4; i >= 1; --i)
	{
		if (A[i] > B[i])
		{
			cout << "A\n";
			break;
		}
		else if (B[i] > A[i])
		{
			cout << "B\n";
			break;
		}
		else if (i == 1)
		{
			cout << "D\n";
		}
	}
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