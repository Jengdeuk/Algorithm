#include <iostream>
#include <string>
using namespace std;

string Students[32];

int GetDistance(string A, string B, string C)
{
	int Distance = 0;

	for (int i = 0; i < 4; ++i)
	{
		if (A[i] != B[i])
		{
			++Distance;
		}

		if (B[i] != C[i])
		{
			++Distance;
		}

		if (C[i] != A[i])
		{
			++Distance;
		}
	}

	return Distance;
}

void Test()
{
	int N;
	cin >> N;
	if (N > 32)
	{
		string Temp;
		for (int i = 0; i < N; ++i)
		{
			cin >> Temp;
		}

		cout << 0 << '\n';
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		cin >> Students[i];
	}

	int MinDistance = 100;
	for (int A = 0; A < N - 2; ++A)
	{
		for (int B = A + 1; B < N - 1; ++B)
		{
			for (int C = B + 1; C < N; ++C)
			{
				MinDistance = min(MinDistance, GetDistance(Students[A], Students[B], Students[C]));
			}
		}
	}
	cout << MinDistance << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}