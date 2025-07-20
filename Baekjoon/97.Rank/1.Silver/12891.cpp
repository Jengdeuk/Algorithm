#include <iostream>
#include <string>
using namespace std;

int N, M, P[4], CP[4];
string S;

int CharToInt(char Ch)
{
	switch (Ch)
	{
	case 'A':
		return 0;
	case 'C':
		return 1;
	case 'G':
		return 2;
	case 'T':
		return 3;
	}

	return -1;
}

bool IsCorrectPW()
{
	for (int i = 0; i < 4; ++i)
	{
		if (CP[i] < P[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> S;
	for (int i = 0; i < 4; ++i)
	{
		cin >> P[i];
	}

	int Cnt = 0;

	int L = 0, R = -1;
	while (R < M - 1)
	{
		CP[CharToInt(S[++R])]++;
	}

	while (R < N && R - L == M - 1)
	{
		Cnt += IsCorrectPW();
		--CP[CharToInt(S[L++])];
		CP[CharToInt(S[++R])]++;
	}
	
	cout << Cnt;
}