#include <iostream>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		ll S;
		cin >> S;

		bool bKey = true;
		for (int j = 1000000; j >= 2; --j)
		{
			if (S % j == 0)
			{
				bKey = false;
				break;
			}
		}

		if (bKey)
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}