#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Sequence;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	Sequence.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Number;
		cin >> Number;
		Sequence.emplace_back(Number);
	}

	sort(Sequence.begin(), Sequence.end());

	cout << Sequence.front() * Sequence.back();
}