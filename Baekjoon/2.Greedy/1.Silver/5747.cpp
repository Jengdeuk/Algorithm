#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		int N;
		cin >> N;
		if (N == 0)
		{
			break;
		}

		int A = 0;
		for (int i = 0; i < N; ++i)
		{
			int Num;
			cin >> Num;
			if (Num % 2 == 0) ++A;
		}

		int B = 0;
		for (int i = 0; i < N; ++i)
		{
			int Num;
			cin >> Num;
			if (Num % 2) ++B;
		}

		cout << abs(A - B) << '\n';
	}
}