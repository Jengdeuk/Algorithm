#include <iostream>
#include <algorithm>
using namespace std;

int A[10];

void Test()
{
	for (int i = 0; i < 10; ++i)
	{
		cin >> A[i];
	}

	sort(A, A + 10);

	cout << A[7] << '\n';
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