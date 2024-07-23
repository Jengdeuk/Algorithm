#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

p Cnt[26];
int R[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 26; ++i)
	{
		Cnt[i].second = i;
	}

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;

		int Digit = 0;
		for (int j = S.size() - 1; j >= 0; --j)
		{
			Cnt[S[j] - 'A'].first += pow(10, Digit++);
		}
	}

	sort(Cnt, Cnt + 26, greater<>());

	int Sum = 0, Num = 9;
	for (int i = 0; i < 26; ++i)
	{
		if (Cnt[i].first == 0)
		{
			break;
		}

		Sum += Cnt[i].first * Num--;
	}

	cout << Sum;
}