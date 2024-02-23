#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	
	for (int i = N; i > 0; --i)
	{
		for (int j = N - i; j > 0; --j)
		{
			cout << ' ';
		}

		for (int j = i; j > 0; --j)
		{
			cout << '*';
		}

		cout << '\n';
	}
}