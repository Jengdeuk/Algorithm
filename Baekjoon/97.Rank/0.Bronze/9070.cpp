#include <iostream>
using namespace std;

void Test()
{
	int N;
	cin >> N;
	
	float Min = 100000;
	int MinC = 100000;
	for (int i = 0; i < N; ++i)
	{
		int W, C;
		cin >> W >> C;
		float M = float(C) / W;
		if (M <= Min)
		{
			MinC = ((M == Min) ? min(MinC, C) : C);
			Min = M;
		}
	}

	cout << MinC << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}