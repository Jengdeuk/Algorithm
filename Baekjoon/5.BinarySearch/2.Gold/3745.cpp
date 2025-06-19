#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Test(int N)
{
	vector<int> V;
	V.reserve(N);

	while (N--)
	{
		int Num;
		cin >> Num;

		if (V.empty() || Num > V.back())
		{
			V.emplace_back(Num);
		}
		else
		{
			V[lower_bound(V.begin(), V.end(), Num) - V.begin()] = Num;
		}
	}

	cout << V.size() << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	while (cin >> N) Test(N);
}