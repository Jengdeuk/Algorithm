#include <iostream>
using namespace std;

int N, K, Seq[200000], Cnt[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;

	int L = 0, MaxLength = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> Seq[i];
		Cnt[Seq[i]]++;
		while (Cnt[Seq[i]] > K)
		{
			Cnt[Seq[L]]--;
			L++;
		}

		MaxLength = max(MaxLength, i + 1 - L);
	}

	cout << MaxLength;
}