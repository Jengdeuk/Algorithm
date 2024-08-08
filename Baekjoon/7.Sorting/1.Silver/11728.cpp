#include <iostream>
using namespace std;

int N, M;
int A[1000000], B[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> B[i];
	}

	int AI = 0, BI = 0;
	while (AI < N && BI < M)
	{
		if (A[AI] <= B[BI])
		{
			cout << A[AI++] << ' ';
		}
		else
		{
			cout << B[BI++] << ' ';
		}
	}

	while (AI < N)
	{
		cout << A[AI++] << ' ';
	}

	while (BI < M)
	{
		cout << B[BI++] << ' ';
	}
}