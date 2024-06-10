#include <iostream>
using namespace std;

int N, M, F, B;
bool Front;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	cin >> F >> B;
	Front = true;

	for (int i = 0; i < M; ++i)
	{
		int K;
		cin >> K;
		if ((Front && F <= K) || (!Front && B <= K))
		{
			Front = !Front;
		}
	}

	if (Front)
	{
		cout << F;
	}
	else
	{
		cout << B;
	}
}