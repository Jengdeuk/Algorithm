#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	ll Sum = 0;

	int N;
	cin >> N;

	stack<int> S;
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;
		if (S.empty() == false)
		{
			while (S.empty() == false && Num >= S.top())
			{
				S.pop();
			}

			Sum += S.size();
		}

		S.emplace(Num);
	}

	cout << Sum;
}