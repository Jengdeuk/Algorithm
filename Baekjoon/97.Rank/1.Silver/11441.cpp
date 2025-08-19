#include <iostream>
using namespace std;

int N, S[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int Num;
		cin >> Num;
		S[i] = S[i - 1] + Num;
	}

	int M;
	cin >> M;
	while (M--)
	{
		int A, B;
		cin >> A >> B;
		cout << S[B] - S[A - 1] << '\n';
	}
}