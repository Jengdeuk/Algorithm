#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i % 2 == 0)
			{
				cout << "* ";
			}
			else
			{
				cout << " *";
			}
		}
		cout << '\n';
	}
}