#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<int, string> p;

int N;
p S[100];

void Test()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i].second >> S[i].first;
	}

	sort(S, S + N);

	cout << S[N - 1].second << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}