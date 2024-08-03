#include <iostream>
#include <algorithm>
using namespace std;

int N, MS, PS, ZS, OS;
int S[50], M[50], P[50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	sort(S, S + N);

	for (int i = 0; i < N; ++i)
	{
		if (S[i] >= 0)
		{
			break;
		}

		M[MS++] = S[i];
	}

	for (int i = N - 1; i >= 0; --i)
	{
		if (S[i] <= 1)
		{
			break;
		}

		P[PS++] = S[i];
	}

	for (int i = 0; i < N; ++i)
	{
		if (S[i] == 1)
		{
			++OS;
		}
	}

	ZS = N - MS - PS - OS;

	int Sum = 0;
	for (int i = 0; i + 1 < MS; i += 2)
	{
		Sum += M[i] * M[i + 1];
	}

	if (MS % 2 == 1 && ZS == 0)
	{
		Sum += M[MS - 1];
	}

	for (int i = 0; i + 1 < PS; i += 2)
	{
		Sum += P[i] * P[i + 1];
	}

	if (PS % 2 == 1)
	{
		Sum += P[PS - 1];
	}

	Sum += OS;

	cout << Sum;
}