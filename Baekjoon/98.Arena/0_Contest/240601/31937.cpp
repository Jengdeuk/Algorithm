#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> pp;

int N, M, K;
bool V[1001], S[1001];
pp Log[10000];

bool Found()
{
	for (int i = 1; i <= N; ++i)
	{
		if (V[i] != S[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

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
		Log[i] = pp(T, p(A, B));
	}

	sort(Log, Log + M);

	for (int R = 1; R <= N; ++R)
	{
		memset(S, false, sizeof(S));
		S[R] = true;

		for (int i = 0; i < M; ++i)
		{
			int A = Log[i].second.first;
			int B = Log[i].second.second;
			if (S[A])
			{
				S[B] = true;
			}
		}

		if (Found())
		{
			cout << R;
			break;
		}
	}
}