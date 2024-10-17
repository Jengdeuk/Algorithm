#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int K;
		cin >> K;
		for (int j = 0; j < K; ++j)
		{
			cout << '=';
		}
		cout << '\n';
	}
}