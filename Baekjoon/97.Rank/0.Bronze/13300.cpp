#include <iostream>
using namespace std;

int Man[6], Wom[6];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;

	int Room = 0;
	for (int i = 0; i < N; ++i)
	{
		int A, B;
		cin >> A >> B;
		--B;
		if (A == 0)
		{
			++Wom[B];
			if (Wom[B] == K)
			{
				Wom[B] = 0;
				++Room;
			}
		}
		else
		{
			++Man[B];
			if (Man[B] == K)
			{
				Man[B] = 0;
				++Room;
			}
		}
	}

	for (int i = 0; i < 6; ++i)
	{
		if (Wom[i] > 0)
		{
			++Room;
		}

		if (Man[i] > 0)
		{
			++Room;
		}
	}

	cout << Room;
}