#include <iostream>
#include <queue>
using namespace std;

queue<int> Seq;
int Result[5000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, K;
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		Seq.emplace(i);
	}

	int Size = 0;
	int Cnt = 1;
	while (!Seq.empty())
	{
		int Current = Seq.front();
		Seq.pop();

		if (Cnt == K)
		{
			Result[Size] = Current;
			++Size;
			Cnt = 1;
		}
		else
		{
			Seq.emplace(Current);
			++Cnt;
		}
	}

	cout << '<';
	for (int i = 0; i < N - 1; ++i)
	{
		cout << Result[i] << ", ";
	}
	cout << Result[N - 1] << '>';
}