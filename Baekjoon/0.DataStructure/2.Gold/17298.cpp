#include <iostream>
#include <stack>
using namespace std;

typedef pair<int, int> p;

int N;
int S[1000000], NGE[1000000];
stack<p> ST;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
		NGE[i] = -1;
	}
	
	for (int i = 0; i < N; ++i)
	{
		int Num = S[i];

		while (!ST.empty() && Num > ST.top().first)
		{
			NGE[ST.top().second] = Num;
			ST.pop();
		}

		ST.emplace(Num, i);
	}

	for (int i = 0; i < N; ++i)
	{
		cout << NGE[i] << ' ';
	}
}