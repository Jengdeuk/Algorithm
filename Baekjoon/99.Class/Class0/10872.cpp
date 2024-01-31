#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int Result = N;
	for (int i = N - 1; i > 0; --i)
	{
		Result *= i;
	}

	if (N == 0)
	{
		cout << 1;
	}
	else
	{
		cout << Result;
	}
}