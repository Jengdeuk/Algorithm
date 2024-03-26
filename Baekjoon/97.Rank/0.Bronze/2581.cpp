#include <iostream>
using namespace std;

bool Prime[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int M, N;
	cin >> M >> N;

	for (int i = 0; i <= N; ++i)
	{
		Prime[i] = true;
	}

	Prime[1] = false;

	for (int i = 2; i <= N / 2; ++i)
	{
		if (!Prime[i])
		{
			continue;
		}

		for (int j = 2; i * j <= N; ++j)
		{
			Prime[i * j] = false;
		}
	}

	int Sum = 0;
	int Min = 100000;
	for (int i = M; i <= N; ++i)
	{
		if (!Prime[i])
		{
			continue;
		}

		Sum += i;
		if (i < Min)
		{
			Min = i;
		}
	}

	if (Sum != 0)
	{
		cout << Sum << '\n';
		cout << Min;
	}
	else
	{
		cout << -1;
	}
}