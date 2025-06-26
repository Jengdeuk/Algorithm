#include <iostream>
#include <unordered_map>
using namespace std;

int N, S[250001];
unordered_map<int, int> UM;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int X;
	cin >> N >> X;
	for (int i = 1; i <= N; ++i)
	{
		int Num;
		cin >> Num;
		S[i] = S[i - 1] + Num;
	}

	int MS = 0;
	for (int i = 1; i <= N - X + 1; ++i)
	{
		int Sum = S[i + X - 1] - S[i - 1];
		UM[Sum]++;
		MS = max(MS, Sum);
	}

	if (MS > 0)
	{
		cout << MS << '\n';
		cout << UM[MS];
	}
	else
	{
		cout << "SAD";
	}
}