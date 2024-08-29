#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;

int N;
p A[50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;
		A[i].first = Num;
		A[i].second = i;
	}

	sort(A, A + N);

	for (int i = 0; i < N; ++i)
	{
		A[i].first = A[i].second;
		A[i].second = i;
	}

	sort(A, A + N);

	for (int i = 0; i < N; ++i)
	{
		cout << A[i].second << ' ';
	}
}