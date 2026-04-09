#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxTime = 200000;

int N, K;
vector<int> E;

bool IsValid(const int T)
{
	int Cnt = 0;

	int Cur = N;
	while (Cnt < K)
	{
		++Cnt;
		if (Cur - T <= 1)
		{
			Cur -= T;
			break;
		}

		Cur = *lower_bound(E.begin(), E.end(), Cur - T);
	}

	return Cur <= 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		int Num;
		cin >> Num;
		if (Num)
		{
			E.emplace_back(i);
		}
	}

	int Answer = MaxTime;
	int L = 1;
	int R = MaxTime;
	while (L <= R)
	{
		int M = (L + R) >> 1;
		if (IsValid(M))
		{
			Answer = M;
			R = M - 1;
		}
		else
		{
			L = M + 1;
		}
	}

	cout << Answer;
}