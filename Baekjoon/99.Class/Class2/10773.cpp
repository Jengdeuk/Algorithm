#include <iostream>
#include <algorithm>
using namespace std;

int Sequence[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int K;
	cin >> K;
	int Size = K;
	int Index = 0;
	for (int i = 0; i < K; ++i)
	{
		int Number;
		cin >> Number;
		Sequence[Index] = Number;
		if (Number == 0)
		{
			Size -= 2;
			Index = clamp(Index - 1, 0, 99999);
		}
		else
		{
			++Index;
		}
	}

	long long Sum = 0;
	for (int i = 0; i < Size; ++i)
	{
		Sum += Sequence[i];
	}
	cout << Sum;
}