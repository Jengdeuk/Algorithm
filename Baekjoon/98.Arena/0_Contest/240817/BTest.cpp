#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

const char SRP[3] = { 'S', 'R', 'P' };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	srand(time(NULL));

	int N = rand() % 50 + 1;
	int M = rand() % 50 + 1;
	int K = rand() % (N - 1) + 1;
	cout << N << ' ' << M << ' ' << K << '\n';
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cout << SRP[rand() % 3];
		}
		cout << '\n';
	}
}