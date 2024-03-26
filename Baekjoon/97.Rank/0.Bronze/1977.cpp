#include <iostream>
using namespace std;

bool Square[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 1; i <= 100; ++i)
	{
		Square[i * i] = true;
	}

	int M, N;
	cin >> M >> N;

	int Sum = 0;
	int Min = 10001;
	for (int i = M; i <= N; ++i)
	{
		if (Square[i])
		{
			Sum += i;
			Min = min(Min, i);
		}
	}

	if (Sum == 0)
	{
		cout << -1;
		return 0;
	}

	cout << Sum << '\n';
	cout << Min;
}