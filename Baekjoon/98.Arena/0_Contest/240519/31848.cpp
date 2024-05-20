#include <iostream>
using namespace std;

int N, Q, Hole[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int H;
		cin >> H;
		Hole[H] = i;
	}

	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		int S;
		cin >> S;
		Hole[S];
	}
}