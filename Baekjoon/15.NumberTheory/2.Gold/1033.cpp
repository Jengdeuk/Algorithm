#include <iostream>
#include <list>
#include <queue>
using namespace std;

typedef long long ll;

typedef pair<ll, ll> p;
typedef pair<int, p> ip;

ll S[10];
list<ip> F[10];

ll GCD(ll A, ll B)
{
	if (B == 0)
	{
		return A;
	}

	return GCD(B, A % B);
}

ll LCM(ll A, ll B)
{
	return (A * B) / GCD(A, B);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	ll ALCM = 1;
	for (int i = 0; i < N - 1; ++i)
	{
		int A, B, P, Q;
		cin >> A >> B >> P >> Q;
		F[A].emplace_back(B, p(P, Q));
		F[B].emplace_back(A, p(Q, P));
		ALCM *= LCM(P, Q);
	}

	queue<int> Q;
	S[0] = ALCM;
	Q.emplace(0);
	while (!Q.empty())
	{
		int Cur = Q.front();
		Q.pop();

		for (const ip& f : F[Cur])
		{
			int Ngb = f.first;
			if (S[Ngb] == 0)
			{
				S[Ngb] = S[Cur] * f.second.second / f.second.first;
				Q.emplace(Ngb);
			}
		}
	}

	ll AGCD = S[0];
	for (int i = 0; i < N; ++i)
	{
		AGCD = GCD(AGCD, S[i]);
	}

	for (int i = 0; i < N; ++i)
	{
		cout << S[i] / AGCD << ' ';
	}
}