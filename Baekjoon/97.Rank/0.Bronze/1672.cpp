#include <iostream>
#include <string>
using namespace std;

const char Order[4][4] =
{
	{ 0, 2, 0, 1 },
	{ 2, 1, 3, 0 },
	{ 0, 3, 2, 1 },
	{ 1, 0, 1, 3 }
};

const char IntToChar[4] = { 'A', 'G', 'C', 'T' };

int M[1000000];

int CharToInt(char Ch)
{
	int Ret = -1;

	switch (Ch)
	{
	case 'A':
		Ret = 0;
		break;

	case 'G':
		Ret = 1;
		break;

	case 'C':
		Ret = 2;
		break;

	case 'T':
		Ret = 3;
		break;
	}

	return Ret;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	
	string S;
	cin >> S;

	for (int i = 0; i < N; ++i)
	{
		M[i] = CharToInt(S[i]);
	}

	for (int i = N - 1; i > 0; --i)
	{
		M[i - 1] = Order[M[i - 1]][M[i]];
	}

	cout << IntToChar[M[0]];
}