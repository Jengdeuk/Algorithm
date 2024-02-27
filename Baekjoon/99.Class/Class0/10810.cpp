#include <iostream>
using namespace std;

int Basket[101];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int I, J, K;
		cin >> I >> J >> K;
		for (int j = I; j <= J; ++j)
		{
			Basket[j] = K;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << Basket[i] << ' ';
	}
}