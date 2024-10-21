#include <iostream>
using namespace std;

typedef long long ll;

int N, M;
ll S[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> N >> M;

	ll Sum = 0;
	for (int i = 1; i <= N; ++i)
	{
		ll Num;
		cin >> Num;
		Sum += Num;
		++S[Sum % M];
	}

	ll Count = S[0];
	for (int i = 0; i < M; ++i)
	{
		Count += S[i] * (S[i] - 1) / 2;
	}

	cout << Count;
}