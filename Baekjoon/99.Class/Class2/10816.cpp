#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> Cards;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Card;
		cin >> Card;
		++Cards[Card];
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int Card;
		cin >> Card;
		cout << Cards[Card] << ' ';
	}
}