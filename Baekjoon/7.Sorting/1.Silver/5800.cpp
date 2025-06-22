#include <iostream>
#include <algorithm>
using namespace std;

int N, S[50];

void Test(int Class)
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	sort(S, S + N, greater<>());

	int Gap = 0;
	for (int i = 1; i < N; ++i)
	{
		Gap = max(Gap, abs(S[i] - S[i - 1]));
	}

	cout << "Class " << Class << '\n';
	cout << "Max " << S[0] << ", Min " << S[N - 1] << ", Largest gap " << Gap << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
	{
		Test(i);
	}
}