#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, Size[6], T, P;
	cin >> N;
	for (int i = 0; i < 6; ++i)
	{
		cin >> Size[i];
	} 
	cin >> T >> P;

	int TN = 0;
	for (int i = 0; i < 6; ++i)
	{
		if (Size[i] == 0)
		{
			continue;
		}

		TN += Size[i] / T + (Size[i] % T ? 1 : 0);
	}

	cout << TN << '\n';
	cout << N / P << ' ' << N % P;
}