#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	string Dial;
	cin >> Dial;
	for (int i = 0; i < N; ++i)
	{
		char Ch = Dial[i];
		if (Ch > 'A' && K >= 'Z' - Ch + 1)
		{
			K -= 'Z' - Ch + 1;
			Dial[i] = 'A';
		}

		if (K == 0)
		{
			break;
		}

		if (i == N - 1)
		{
			while (K > 0)
			{
				++Dial[i];
				if (Dial[i] > 'Z')
				{
					Dial[i] = 'A';
				}
				--K;
			}
		}
	}

	cout << Dial;
}