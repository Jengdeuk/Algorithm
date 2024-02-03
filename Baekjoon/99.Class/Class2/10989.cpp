#include <iostream>
using namespace std;

int Sequence[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int Number;
	for (int i = 0; i < N; ++i)
	{
		cin >> Number;
		++Sequence[Number];
	}

	for (int i = 1; i < 10001; ++i)
	{
		while (Sequence[i] > 0)
		{
			cout << i << '\n';
			--Sequence[i];
		}
	}
}