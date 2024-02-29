#include <iostream>
#include <string>
using namespace std;

int N, M, C;
bool Broken[10];

bool IsPossible(string CurrentChannel, int Size)
{
	for (int i = 0; i < Size; ++i)
	{
		int Number = CurrentChannel[i] - '0';
		if (Broken[Number])
		{
			return false;
		}
	}

	return true;
}

int CountPush(int Target)
{
	int Push = 1000000;

	for (int Current = 0; Current <= 1000000; ++Current)
	{
		string CurrentChannel = to_string(Current);
		int Size = CurrentChannel.size();
		if (!IsPossible(CurrentChannel, Size))
		{
			continue;
		}

		Push = min(Push, abs(Target - Current) + Size);
	}

	return Push;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int Button;
		cin >> Button;
		Broken[Button] = true;
	}

	cout << min(abs(N - 100), CountPush(N));
}