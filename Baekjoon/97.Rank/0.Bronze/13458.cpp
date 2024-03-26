#include <iostream>
using namespace std;

int StudentNum[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> StudentNum[i];
	}

	long long A, B;
	cin >> A >> B;

	long long Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		long long Num = StudentNum[i];
		Num = (Num - A < 0) ? 0 : Num - A;
		Cnt += (Num / B) + 1;
		if (Num % B != 0)
		{
			++Cnt;
		}
	}

	cout << Cnt;
}