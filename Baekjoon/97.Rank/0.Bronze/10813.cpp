#include <iostream>
using namespace std;

int Basket[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		Basket[i] = i;
	}

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;

		int Temp = Basket[A];
		Basket[A] = Basket[B];
		Basket[B] = Temp;
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << Basket[i] << ' ';
	}
}