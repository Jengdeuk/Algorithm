#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

typedef pair<int, ll> p;

int N;
p S[200000];

bool Compare(const p& L, const p& R)
{
	return (L.second == R.second ? L.first < R.first : L.second > R.second);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i].first >> S[i].second;
	}

	sort(S, S + N, Compare);

	ll Sum = 0;
	int Time = N;
	for (int i = 0; i < N; ++i)
	{
		if (Time <= S[i].first)
		{
			Sum += S[i].second;
			if (--Time == 0)
			{
				break;
			}
		}
	}

	cout << Sum;
}