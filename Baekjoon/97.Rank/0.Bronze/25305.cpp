#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Score;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, k;
	cin >> N >> k;
	Score.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;
		Score.emplace_back(Num);
	}

	sort(Score.begin(), Score.end(), greater<>());

	cout << Score[k - 1];
}