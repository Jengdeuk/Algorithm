#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		int A, B, C;
		cin >> A >> B >> C;
		
		if (A != -1 && B != -1 && C != -1)
		{
			if (A <= B && B <= C)
			{
				++Cnt;
			}
		}
		else if (A != -1 && B != -1 && C == -1)
		{
			if (A <= B)
			{
				++Cnt;
			}
		}
		else if (A != -1 && B == -1 && C == -1)
		{
			++Cnt;
		}
	}

	cout << Cnt;
}