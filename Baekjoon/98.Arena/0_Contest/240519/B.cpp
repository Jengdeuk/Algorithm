#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int Card[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> Card[i];
	}

	sort(Card, Card + N, greater<>());

	M = min(M, N / 2 + N % 2);

	int Score = 0;
	for (int i = 0; i < M; ++i)
	{
		if (Card[i] <= 0)
		{
			break;
		}

		Score += Card[i];
	}

	cout << Score;
}