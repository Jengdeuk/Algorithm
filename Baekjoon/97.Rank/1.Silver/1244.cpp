#include <iostream>
using namespace std;

int N;
bool S[101];

void Boy(int Num)
{
	for (int i = 1; Num * i <= N; ++i)
	{
		S[Num * i] = !S[Num * i];
	}
}

void Girl(int Num)
{
	S[Num] = !S[Num];
	int Idx = 1;
	while (Num - Idx >= 1 && Num + Idx <= N)
	{
		if (S[Num - Idx] != S[Num + Idx])
		{
			break;
		}

		S[Num - Idx] = !S[Num - Idx];
		S[Num + Idx] = !S[Num + Idx];
		++Idx;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> S[i];
	}

	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		int A, B;
		cin >> A >> B;
		switch (A)
		{
		case 1:
			Boy(B);
			break;

		case 2:
			Girl(B);
			break;
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		cout << S[i];
		if (i % 20 == 0)
		{
			cout << '\n';
		}
		else
		{
			cout << ' ';
		}
	}
}