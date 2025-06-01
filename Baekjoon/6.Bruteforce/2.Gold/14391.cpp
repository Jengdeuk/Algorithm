#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int DX[2] = { 0, 1 };
const int DY[2] = { 1, 0 };

int N, M, MSum;
char Num[4][4];
bool W[4][4], V[4][4];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < M && V[R][C] == false);
}

void Bruteforce(int Idx)
{
	if (Idx == N * M)
	{
		string S;
		memset(V, false, sizeof(V));

		int Sum = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (V[i][j])
				{
					continue;
				}

				int R = i, C = j;
				V[R][C] = true;
				S.push_back(Num[R][C]);

				int Dir = W[R][C];
				int NR = R + DY[Dir];
				int NC = C + DX[Dir];
				while (IsValid(NR, NC) && W[NR][NC] == Dir)
				{
					V[NR][NC] = true;
					S.push_back(Num[NR][NC]);

					NR += DY[Dir];
					NC += DX[Dir];
				}

				Sum += stoi(S);
				string().swap(S);
			}
		}

		MSum = max(MSum, Sum);

		return;
	}

	int R = Idx / M, C = Idx % M;

	W[R][C] = true;
	Bruteforce(Idx + 1);

	W[R][C] = false;
	Bruteforce(Idx + 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		for (int j = 0; j < M; ++j)
		{
			Num[i][j] = S[j];
		}
	}

	Bruteforce(0);

	cout << MSum;
}