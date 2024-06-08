#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int N, Idx;
int A[4000], B[4000], C[4000], D[4000];
int AB[16000000], CD[16000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i] >> B[i] >> C[i] >> D[i];
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			AB[Idx] = A[i] + B[j];
			CD[Idx] = C[i] + D[j];
			++Idx;
		}
	}

	sort(CD, CD + Idx);

	ll Cnt = 0;
	for (int i = 0; i < Idx; ++i)
	{
		int Num = -1 * AB[i];
		int I1 = lower_bound(CD, CD + Idx, Num) - CD;
		int I2 = upper_bound(CD, CD + Idx, Num) - CD;
		Cnt += (CD[I1] == Num ? I2 - I1 : 0);
	}

	cout << Cnt;
}