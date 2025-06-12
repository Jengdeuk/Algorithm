#include <iostream>
using namespace std;

int N, M;
bool CutR[100], CutC[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;

	int T;
	cin >> T;
	while (T--)
	{
		int Dir, Line;
		cin >> Dir >> Line;
		if (Dir == 0)
		{
			CutR[Line] = true;
		}
		else
		{
			CutC[Line] = true;
		}
	}

	int MC = 0;
	int Length = 0;
	for (int i = 1; i < N; ++i)
	{
		Length++;
		if (CutC[i])
		{
			MC = max(MC, Length);
			Length = 0;
		}
	}

	MC = max(MC, Length + 1);

	int MR = 0;
	Length = 0;
	for (int i = 1; i <	M; ++i)
	{
		Length++;
		if (CutR[i])
		{
			MR = max(MR, Length);
			Length = 0;
		}
	}

	MR = max(MR, Length + 1);

	cout << MR * MC;
}