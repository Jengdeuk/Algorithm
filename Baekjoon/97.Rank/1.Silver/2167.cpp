#include <iostream>
using namespace std;

int N, M;
int S[301][301];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			int Num;
			cin >> Num;
			S[i][j] = S[i][j - 1] + S[i - 1][j] + Num - S[i - 1][j - 1];
		}
	}

	int K;
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		int A, B, C, D;
		cin >> A >> B >> C >> D;
		cout << S[C][D] + S[A - 1][B - 1] - (S[C][B - 1] + S[A - 1][D]) << '\n';
	}
}