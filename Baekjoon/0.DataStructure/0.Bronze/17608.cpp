#include <iostream>
using namespace std;

int N;
int S[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	int Count = 1, T = S[N - 1];
	for (int i = N - 2; i >= 0; --i)
	{
		if (S[i] > T)
		{
			T = S[i];
			++Count;
		}
	}

	cout << Count;
}