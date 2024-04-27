#include <iostream>
using namespace std;

typedef long long ll;

int N, K;
ll Sum[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int Num;
		cin >> Num;
		Sum[i] = Sum[i - 1] + Num;
	}

	cin >> K;
	
	ll Cnt = 0;
	int L = 1, R = N;
	for (int L = 1; L <= N; ++L)
	{
		for (int R = N; R >= 1; --R)
		{
			if (Sum[R] - Sum[L - 1] > K)
			{
				++Cnt;
			}
			else
			{
				break;
			}
		}
	}

	cout << Cnt;
}