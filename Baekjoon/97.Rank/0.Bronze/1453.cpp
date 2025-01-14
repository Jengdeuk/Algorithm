#include <iostream>
using namespace std;

bool sit[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		if (sit[num - 1])
		{
			++cnt;
		}
		else
		{
			sit[num - 1] = true;
		}
	}

	cout << cnt;
}