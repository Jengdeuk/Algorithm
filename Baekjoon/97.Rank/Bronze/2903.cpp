#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Cnt = 1;
	int Dot = 3;

	int N;
	cin >> N;
	while (Cnt < N)
	{
		Dot += Dot - 1;
		++Cnt;
	}

	cout << Dot * Dot;
}