#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int Cnt = 0;
	for (int i = 5; i <= N; i *= 5)
	{
		Cnt += N / i;
	}

	cout << Cnt;
}