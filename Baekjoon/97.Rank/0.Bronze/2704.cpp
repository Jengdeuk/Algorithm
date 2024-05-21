#include <iostream>
#include <string>
using namespace std;

int D[3][6];

void Input(int R, int Num)
{
	string S;
	while (Num > 0)
	{
		S.push_back(Num % 2 + '0');
		Num /= 2;
	}

	int Size = 6 - S.size();
	for (int i = 0; i < Size; ++i)
	{
		S.push_back('0');
	}

	for (int i = 5; i >= 0; --i)
	{
		D[R][5 - i] = S[i] - '0';
	}
}

void Test()
{
	string Str;
	cin >> Str;

	for (int i = 0; i < 3; ++i)
	{
		int Num = stoi(Str.substr(i * 3, 2));
		Input(i, Num);
	}

	for (int j = 0; j < 6; ++j)
	{
		for (int i = 0; i < 3; ++i)
		{
			cout << D[i][j];
		}
	}
	cout << ' ';

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			cout << D[i][j];
		}
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		Test();
	}
}