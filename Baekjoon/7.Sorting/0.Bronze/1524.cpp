#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int S[1000000], B[1000000];

void Test()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	for (int i = 0; i < M; ++i)
	{
		cin >> B[i];
	}

	sort(S, S + N);
	sort(B, B + M);

	int SI = 0, BI = 0;
	while (SI < N && BI < M)
	{
		if (B[BI] <= S[SI])
		{
			++BI;
		}
		else
		{
			++SI;
		}
	}

	if (SI == N)
	{
		cout << "B\n";
	}
	else
	{
		cout << "S\n";
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