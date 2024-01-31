#include <iostream>
#include <vector>
using namespace std;

vector<int> Sequence;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	Sequence.reserve(N);

	for (int i = 0; i < N; ++i)
	{
		int Number;
		cin >> Number;
		Sequence.emplace_back(Number);
	}

	int V;
	cin >> V;

	int Count = 0;
	for (const int& Number : Sequence)
	{
		if (Number == V)
		{
			++Count;
		}
	}

	cout << Count;
}