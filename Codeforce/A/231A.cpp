#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	
	int cnt = 0;
	while (n--)
	{
		int sum = 0;
		for (int i = 0; i < 3; ++i)
		{
			int check;
			cin >> check;
			sum += check;
		}
		
		cnt += (sum >= 2);
	}

	cout << cnt;
}