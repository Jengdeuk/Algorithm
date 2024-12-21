#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int N, S[10];
bool LG[9], V[10];
string Max("0"), Min("9999999999");

void Backtracking(int Idx)
{
	if (Idx == N + 1)
	{
		string Str;
		for (int i = 0; i < N + 1; ++i)
		{
			Str.push_back(S[i] + '0');
		}

		ll Cur = stoll(Str);
		if (Cur > stoll(Max))
		{
			Max = Str;
		}

		if (Cur < stoll(Min))
		{
			Min = Str;
		}

		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (V[i] || (LG[Idx - 1] && i > S[Idx - 1]) || (!LG[Idx - 1] && i < S[Idx - 1]))
		{
			continue;
		}

		V[i] = true;
		S[Idx] = i;
		Backtracking(Idx + 1);
		V[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		char Ch;
		cin >> Ch;
		if (Ch == '>')
		{
			LG[i] = true;
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		V[i] = true;
		S[0] = i;
		Backtracking(1);
		V[i] = false;
	}

	cout << Max << '\n';
	cout << Min;
}