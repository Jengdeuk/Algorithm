#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N;
p P[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> P[i].first >> P[i].second;
	}

	sort(P, P + N);

	int MH = 0, MI = 0;
	for (int i = 0; i < N; ++i)
	{
		if (P[i].second > MH)
		{
			MH = P[i].second;
			MI = i;
		}
	}

	int Sum = 0, H = 0;
	for (int i = 0; i < MI; ++i)
	{
		if (P[i].second > H)
		{
			H = P[i].second;
		}

		Sum += (P[i + 1].first - P[i].first) * H;
	}

	Sum += MH;

	H = 0;
	for (int i = N - 1; i > MI; --i)
	{
		if (P[i].second > H)
		{
			H = P[i].second;
		}

		Sum += (P[i].first - P[i - 1].first) * H;
	}

	cout << Sum;
}