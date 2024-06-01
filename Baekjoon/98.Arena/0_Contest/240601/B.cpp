#include <iostream>
using namespace std;

bool V[1001];
int P[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;

	for (int i = 0; i < K; ++i)
	{
		int C;
		cin >> C;
		V[C] = true;
	}

	for (int i = 0; i < M; ++i)
	{
		int T, A, B;
		cin >> T >> A >> B;
		if (V[A] && V[B])
		{
			++P[B];
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		if (V[i] && P[i] == 0)
		{
			cout << i;
			break;
		}
	}
}