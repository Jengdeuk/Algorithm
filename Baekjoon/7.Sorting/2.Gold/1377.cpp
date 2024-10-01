#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N;
p A[500000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i].first;
		A[i].second = i;
	}

	sort(A, A + N);

	int Max = 0;
	for (int i = 0; i < N; ++i)
	{
		Max = max(Max, A[i].second - i);
	}

	cout << Max + 1;
}