#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Sequence;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	while (N > 0)
	{
		Sequence.emplace_back(N % 10);
		N /= 10;
	}

	sort(Sequence.begin(), Sequence.end(), greater<>());

	for (const int& Number : Sequence)
	{
		cout << Number;
	}
}