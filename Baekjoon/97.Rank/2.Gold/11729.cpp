#include <iostream>
using namespace std;

void Count(int N)
{
	int Cnt = 1;
	while (--N)
	{
		Cnt = Cnt * 2 + 1;
	}
	
	cout << Cnt << '\n';
}

void Move(int A, int B, int C, int N)
{
	if (N == 1)
	{
		cout << A << ' ' << C << '\n';
		return;
	}

	Move(A, C, B, N - 1);
	cout << A << ' ' << C << '\n';
	Move(B, A, C, N - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	Count(N);
	Move(1, 2, 3, N);
}