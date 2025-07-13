#include <iostream>
#include <algorithm>
using namespace std;

int N, L[10000];

void Test()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> L[i];
	}

	sort(L, L + N);
	
	int MGap = 0;
	for (int i = 0; i < N - 2; i += 2)
	{
		MGap = max(MGap, L[i + 2] - L[i]);
	}

	for (int i = 1; i < N - 2; i += 2)
	{
		MGap = max(MGap, L[i + 2] - L[i]);
	}

	cout << MGap << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) Test();
}