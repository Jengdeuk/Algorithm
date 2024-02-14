#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> Coins;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int Coin;
		cin >> Coin;
		Coins.emplace(Coin);
	}

	int Count = 0;
	int Left = K;
	while (!Coins.empty())
	{
		int Coin = Coins.top();
		Coins.pop();

		if (Coin > Left)
		{
			continue;
		}

		Count += (Left / Coin);
		Left %= Coin;

		if (Left == 0)
		{
			break;
		}
	}

	cout << Count;
}