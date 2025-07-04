#include <iostream>
#include <set>
using namespace std;

set<int> S;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	while (N--)
	{
		int Num;
		cin >> Num;
		S.emplace(Num);
	}

	while (M--)
	{
		int Num;
		cin >> Num;
		if (S.count(Num))
		{
			S.erase(S.find(Num));
		}
	}

	cout << S.size() << '\n';
	for (const int Num : S)
	{
		cout << Num << ' ';
	}
}