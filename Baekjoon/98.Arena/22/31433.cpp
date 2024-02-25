#include <iostream>
#include <string>
using namespace std;

int N;

int Check(string Current)
{
	int Cnt = 0;

	int Size = min(N, int(Current.size()));

	for (int i = 0; i < Size; ++i)
	{
		if (i % 3 == 0 && Current[i] == 'K')
		{
			++Cnt;
		}
		else if (i % 3 == 1 && Current[i] == 'S')
		{
			++Cnt;
		}
		else if (i % 3 == 2 && Current[i] == 'A')
		{
			++Cnt;
		}
	}

	return Cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string X;
	cin >> X;
	N = X.size();

	for (int i = 0; i < X.size(); ++i)
	{
		if (i % 3 == 0 && X[i] != 'K')
		{
			return false;
		}
		else if (i % 3 == 1 && X[i] != 'S')
		{
			return false;
		}
		else if (i % 3 == 2 && X[i] != 'A')
		{
			return false;
		}
	}
}