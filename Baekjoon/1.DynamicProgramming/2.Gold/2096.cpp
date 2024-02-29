#include <iostream>
using namespace std;

int Max[2][3];
int Min[2][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int A, B, C;
	cin >> A >> B >> C;

	Max[0][0] = A;
	Max[0][1] = B;
	Max[0][2] = C;

	Min[0][0] = A;
	Min[0][1] = B;
	Min[0][2] = C;

	for (int i = 1; i < N; ++i)
	{
		cin >> A >> B >> C;

		int Current = i % 2;
		int Previous = (i - 1) % 2;

		Max[Current][0] = A + max(Max[Previous][0], Max[Previous][1]);
		Max[Current][1] = B + max(max(Max[Previous][0], Max[Previous][1]), Max[Previous][2]);
		Max[Current][2] = C + max(Max[Previous][1], Max[Previous][2]);

		Min[Current][0] = A + min(Min[Previous][0], Min[Previous][1]);
		Min[Current][1] = B + min(min(Min[Previous][0], Min[Previous][1]), Min[Previous][2]);
		Min[Current][2] = C + min(Min[Previous][1], Min[Previous][2]);
	}

	int Last = (N - 1) % 2;
	int MaxNum = max(max(Max[Last][0], Max[Last][1]), Max[Last][2]);
	int MinNum = min(min(Min[Last][0], Min[Last][1]), Min[Last][2]);

	cout << MaxNum << ' ' << MinNum;
}