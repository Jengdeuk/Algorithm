#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Basket;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	Basket.reserve(N);
	for (int i = 1; i <= N; ++i)
	{
		Basket.emplace_back(i);
	}

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;
		
		reverse(Basket.begin() + (A - 1), Basket.begin() + B);
	}

	for (const int& Number : Basket)
	{
		cout << Number << ' ';
	}
}