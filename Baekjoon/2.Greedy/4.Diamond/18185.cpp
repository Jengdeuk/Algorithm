#include <iostream>
using namespace std;

int Factory[10002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Factory[i];
	}

	int Price = 0;
	for (int i = 0; i < N; ++i)
	{
		int Num;
		if (Factory[i + 1] > Factory[i + 2])
		{
			Num = min(Factory[i], Factory[i + 1] - Factory[i + 2]);
			Price += Num * 5;
			Factory[i] -= Num;
			Factory[i + 1] -= Num;
		}

		Num = min(Factory[i], min(Factory[i + 1], Factory[i + 2]));
		Price += Num * 7;
		Factory[i] -= Num;
		Factory[i + 1] -= Num;
		Factory[i + 2] -= Num;

		Price += Factory[i] * 3;
	}

	cout << Price;
}