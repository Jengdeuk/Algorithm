#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		int M, F;
		cin >> M >> F;
		
		if (M == 0 && F == 0)
		{
			break;
		}

		cout << M + F << '\n';
	}
}