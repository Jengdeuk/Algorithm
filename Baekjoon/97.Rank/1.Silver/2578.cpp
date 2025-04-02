#include <iostream>
using namespace std;

typedef pair<int, int> p;

const int mSize = 5;

p pos[26];
bool c[mSize][mSize];

int countLine()
{
	int line = 0;
	for (int i = 0; i < mSize; ++i)
	{
		bool isBingo = true;
		for (int j = 0; j < mSize; ++j)
		{
			if (c[i][j] == false)
			{
				isBingo = false;
				break;
			}
		}

		line += isBingo;
	}

	for (int j = 0; j < mSize; ++j)
	{
		bool isBingo = true;
		for (int i = 0; i < mSize; ++i)
		{
			if (c[i][j] == false)
			{
				isBingo = false;
				break;
			}
		}

		line += isBingo;
	}

	{
		bool isBingo = true;
		for (int i = 0; i < mSize; ++i)
		{
			if (c[i][i] == false)
			{
				isBingo = false;
				break;
			}
		}

		line += isBingo;
	}

	{
		bool isBingo = true;
		for (int i = 0; i < mSize; ++i)
		{
			if (c[i][mSize - 1 - i] == false)
			{
				isBingo = false;
				break;
			}
		}

		line += isBingo;
	}

	return line;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			int num;
			cin >> num;
			pos[num] = p(i, j);
		}
	}

	bool isFinished = false;
	int answer = 0;
	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			int num;
			cin >> num;
			c[pos[num].first][pos[num].second] = true;
			if (isFinished == false && countLine() >= 3)
			{
				isFinished = true;
				answer = mSize * i + j + 1;
			}
		}
	}

	cout << answer;
}