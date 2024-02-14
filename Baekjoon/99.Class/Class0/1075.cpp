#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, F;
	cin >> N >> F;

	N = (N / 100) * 100;
	while (N % F != 0)
	{
		++N;
	}
	N %= 100;

	cout << setw(2) << setfill('0') << N;
}