#include <iostream>
using namespace std;

typedef long long ll;

int X, M;
ll Sum;

void Magic(int Power, int N)
{
	Sum += Power;
	if (Power == 0 || N == 0)
	{
		return;
	}

	Magic(Power / 2, N - 1);
	Magic(Power / 2 + (Power % 2), N - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> X >> M;
	Magic(X, M);

	cout << Sum;
}