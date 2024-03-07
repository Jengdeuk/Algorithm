#include <iostream>
#include <cstring>
using namespace std;

char* Max(char* A, char* B)
{
	for (int i = 0; i < strlen(A); ++i)
	{
		if (A[i] < B[i])
		{
			return B;
		}
		if (A[i] > B[i])
		{
			return A;
		}
	}

	return A;
}

void Subtract(char* A, char* B, char* C, int i)
{
	C[i] = '0';
	while (A[i - 1] > '0' || Max(A + i, B) == A + i)
	{
		char* SA = A + i;

		for (int j = 0; j < strlen(B); ++j)
		{
			SA[j] = SA[j] - B[j] + '0';
			if (SA[j] < '0')
			{
				SA[j] += 10;
				--SA[j - 1];
			}
		}
		for (int j = strlen(B) - 1; j >= 0; --j)
		{
			if (SA[j] < '0')
			{
				SA[j] += 10;
				--SA[j - 1];
			}
		}

		++C[i];
	}
}

void Divide(char* A, char* B, char* C)
{
	int Length = strlen(A) - strlen(B);

	int i = 0;
	while (i <= Length)
	{
		Subtract(A, B, C, i++);
	}

	C[i] = '\0';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	char A[1001];
	char B[1001];
	char C[1001];
	cin >> A >> B;

	Divide(A, B, C);

	int CIdx = 0;
	while (C[CIdx] == '0')
	{
		++CIdx;
	}
	if (C[0] == '\0')
	{
		C[0] = '0';
		C[1] = '\0';
	}
	if (C[CIdx] == '\0')
	{
		--CIdx;
	}

	int AIdx = 0;
	while (A[AIdx] == '0')
	{
		++AIdx;
	}
	if (A[AIdx] == '\0')
	{
		--AIdx;
	}

	cout << C + CIdx << '\n';
	cout << A + AIdx << '\n';
}