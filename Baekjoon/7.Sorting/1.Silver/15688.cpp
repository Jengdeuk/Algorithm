#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	vector<int> V;
	V.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;
		V.emplace_back(Num);
	}

	sort(V.begin(), V.end());

	for (const int Num : V)
	{
		cout << Num << '\n';
	}
}