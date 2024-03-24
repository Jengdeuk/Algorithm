#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	long long S;
	cin >> S;
	
	long long i = 1;
	long long N = 0;
	while (S > 0)
	{
		if (S - i >= 0)
		{
			S -= i;
			++N;
		}
		else
		{
			break;
		}

		++i;
	}

	cout << N;
}