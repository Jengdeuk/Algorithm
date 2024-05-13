#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

unordered_map<string, int> Value;

void Init()
{
	Value["a"] = 1; Value["b"] = 2; Value["k"] = 3; Value["d"] = 4; Value["e"] = 5;
	Value["g"] = 6; Value["h"] = 7; Value["i"] = 8; Value["l"] = 9; Value["m"] = 10;
	Value["n"] = 11; Value["ng"] = 12; Value["o"] = 13; Value["p"] = 14; Value["r"] = 15;
	Value["s"] = 16; Value["t"] = 17; Value["u"] = 18; Value["w"] = 19; Value["y"] = 20;
}

bool Compare(const string& L, const string& R)
{
	int LS = L.size();
	int RS = R.size();
	int Size = min(LS, RS);
	for (int i = 0; i < Size; ++i)
	{
		if (L[i] == 'n' && i + 1 < Size && L[i + 1] == 'g' && R[i + 1] != 'g')
		{
			string str;
			return (Value["ng"] < Value[str + R[i]]);
		}
		else if (R[i] == 'n' && i + 1 < Size && R[i + 1] == 'g' && L[i + 1] != 'g')
		{
			string str;
			return (Value[str + L[i]] < Value["ng"]);
		}
		else if (L[i] != R[i])
		{
			string str;
			return (Value[str + L[i]] < Value[str + R[i]]);
		}
	}

	return (LS < RS);
}

string S[50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Init();

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	sort(S, S + N, Compare);

	for (int i = 0; i < N; ++i)
	{
		cout << S[i] << '\n';
	}
}