#include <iostream>
using namespace std;

int Pre[97];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 97; ++i)
	{
		Pre[i] = -1;
	}

	int N, P;
	cin >> N >> P;
	
	int Count = 0;
	int Nxt = N;
	while (true)
	{
		int Cur = Nxt;
		Nxt = Cur * N % P;
		if (Nxt == Cur)
		{
			Count = 1;
			break;
		}

		if (Pre[Nxt] == -1)
		{
			Pre[Nxt] = Cur;
		}
		else
		{
			while (Pre[Cur] != Nxt)
			{
				++Count;
				Cur = Pre[Cur];
			}
			Count += 2;
			break;
		}
	}

	cout << Count;
}