#include <iostream>
using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	char sequence[101] = "";
	cin >> sequence;

	int sum = 0;
	for (int i = 0; i < n; ++i)
	{
		sum += sequence[i] - '0';
	}

	cout << sum;
}