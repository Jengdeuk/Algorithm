#include <iostream>
#include <stack>
using namespace std;

typedef pair<int, int> p;

int N;
stack<p> S;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int H;
		cin >> H;

		while (!S.empty() && S.top().first < H)
		{
			S.pop();
		}

		if (S.empty())
		{
			cout << 0 << ' ';
		}
		else
		{
			cout << S.top().second << ' ';
		}

		S.emplace(H, i);
	}
}