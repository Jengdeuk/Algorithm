#include <iostream>
#include <queue>
using namespace std;

queue<int> Circle;
vector<int> Sequence;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	Sequence.reserve(N);

	int Count = 0;
	for (int i = 1; i <= N; ++i)
	{
		++Count;
		if (Count == K)
		{
			Sequence.emplace_back(i);
			Count = 0;
			continue;
		}

		Circle.emplace(i);
	}

	while (!Circle.empty())
	{
		int Number = Circle.front();
		Circle.pop();

		++Count;
		if (Count == K)
		{
			Sequence.emplace_back(Number);
			Count = 0;
			continue;
		}

		Circle.emplace(Number);
	}

	cout << '<';
	int i = 0;
	for (const int& Number : Sequence)
	{
		cout << Number;

		if (i < N - 1)
		{
			cout << ", ";
		}

		++i;
	}
	cout << '>';
}