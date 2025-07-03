#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void Move(int N, int A, int B, int C)
{
	if (N == 0)
	{
		return;
	}

	Move(N - 1, A, C, B);
	cout << A << ' ' << C << '\n';
	Move(N - 1, B, A, C);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	string Str = to_string(pow(2, N));
	int Idx = Str.find('.');
	Str = Str.substr(0, Idx);
	Str.back() -= 1;
	cout << Str << '\n';
	if (N <= 20)
	{
		Move(N, 1, 2, 3);
	}
}