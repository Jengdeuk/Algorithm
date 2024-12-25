#include <iostream>
#include <algorithm>
using namespace std;

int N;
int M[2250000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;

	int Idx = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> M[Idx++];
		}
	}

	sort(M, M + N * N, greater<int>());

	cout << M[N - 1];
}