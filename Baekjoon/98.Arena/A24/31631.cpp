#include <iostream>
using namespace std;

int Height[5000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	if (N % 2 == 0)
	{
		Height[N / 2 - 1] = 1;
	}
	else
	{
		Height[N / 2] = 1;
	}

	int H = 5000;
	int S = 0;
	int E = N - 1;
	while (Height[S] == 0 || Height[E] == 0)
	{
		if (Height[E] == 0)
		{
			Height[E] = H;
			--H;
		}

		if (Height[S] == 0)
		{
			Height[S] = H;
			--H;
		}

		++S;
		--E;
	}

	for (int i = 0; i < N; ++i)
	{
		cout << Height[i] << ' ';
	}
}