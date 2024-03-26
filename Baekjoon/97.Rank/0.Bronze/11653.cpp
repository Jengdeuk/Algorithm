#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	if (N == 1)
	{
		return 0;
	}
	
	while (N > 1)
	{
		for (int i = 2; i <= N; ++i)
		{
			while (N % i == 0)
			{
				N /= i;
				cout << i << '\n';
			}
		}
	}
}