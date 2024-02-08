#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Sequence;

int BinarySearch(int N, int Number)
{
	int Left = 0;
	int Right = N - 1;
	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;

		if (Sequence[Mid] == Number)
		{
			return 1;
		}
		else if (Sequence[Mid] > Number)
		{
			Right = Mid - 1;
		}
		else
		{
			Left = Mid + 1;
		}
	}

	return 0;
}

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

	sort(Sequence.begin(), Sequence.end());

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int Number;
		cin >> Number;
		cout << BinarySearch(N, Number) << '\n';
	}
}