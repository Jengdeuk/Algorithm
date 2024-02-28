#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	bool bFound = false;
	int Cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (N % i != 0)
		{
			continue;
		}

		++Cnt;
		if (Cnt == K)
		{
			bFound = true;
			cout << i;
			break;
		}
	}

	if (!bFound)
	{
		cout << 0;
	}
}