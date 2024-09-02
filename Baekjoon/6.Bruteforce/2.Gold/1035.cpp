#include <iostream>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

typedef pair<int, int> p;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N;
bool M[5][5], V[1 << 25];

void ConvertBitToMap(int Bit)
{
	memset(M, false, sizeof(M));

	for (int i = 0; i < 25; ++i)
	{
		if (Bit & (1 << i))
		{
			M[i / 5][i % 5] = true;
		}
	}
}

int ConvertMapToBit()
{
	int Bit = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (M[i][j])
			{
				Bit += (1 << (5 * i + j));
			}
		}
	}

	return Bit;
}

bool IsValid(int R, int C)
{
	return (R >= 0 && R < 5 && C >= 0 && C < 5);
}

bool IsCompleted()
{
	int Cnt = 0;
	bool Vst[5][5] = {};

	queue<p> Q;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			if (M[i][j])
			{
				++Cnt;
				Vst[i][j] = true;
				Q.emplace(i, j);
				i = 5;
				j = 5;
				break;
			}
		}
	}

	while (!Q.empty())
	{
		int R = Q.front().first;
		int C = Q.front().second;
		Q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsValid(NR, NC) && M[NR][NC] && !Vst[NR][NC])
			{
				++Cnt;
				Vst[NR][NC] = true;
				Q.emplace(NR, NC);
			}
		}
	}

	if (Cnt == N)
	{
		return true;
	}

	return false;
}

int BFS()
{
	int Answer = 0;

	queue<p> Q;
	int StartBit = ConvertMapToBit();
	V[StartBit] = true;
	Q.emplace(StartBit, 0);
	while (!Q.empty())
	{
		int Bit = Q.front().first;
		int Cnt = Q.front().second;
		Q.pop();

		ConvertBitToMap(Bit);
		if (IsCompleted())
		{
			Answer = Cnt;
			break;
		}

		for (int i = 0; i < 5; ++i)
		{
			for (int j = 0; j < 5; ++j)
			{
				if (M[i][j] == false)
				{
					continue;
				}

				for (int k = 0; k < 4; ++k)
				{
					int NR = i + DY[k];
					int NC = j + DX[k];
					if (!IsValid(NR, NC) || M[NR][NC])
					{
						continue;
					}

					M[i][j] = false;
					M[NR][NC] = true;

					int NxtBit = ConvertMapToBit();
					if (!V[NxtBit])
					{
						V[NxtBit] = true;
						Q.emplace(NxtBit, Cnt + 1);
					}

					M[i][j] = true;
					M[NR][NC] = false;
				}
			}
		}
	}

	return Answer;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 5; ++i)
	{
		string S;
		cin >> S;
		for (int j = 0; j < 5; ++j)
		{
			if (S[j] == '*')
			{
				M[i][j] = true;
				++N;
			}
		}
	}

	cout << BFS();
}