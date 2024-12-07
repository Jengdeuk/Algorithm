#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int Count = 0;
	for (int i = N; i >= 1; --i)
	{
		int Sum = 0;
		for (int j = i; j >= 1; --j)
		{
			Sum += j;
			if (Sum == N)
			{
				++Count;
				break;
			}
			else if (Sum > N)
			{
				break;
			}
		}
	}

	cout << Count;
}