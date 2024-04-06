#include <iostream>
#include <algorithm>
using namespace std;

int Seq[5000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> Seq[i];
	}

	sort(Seq, Seq + N);

	cout << Seq[K - 1];
}