#include <iostream>
#include <vector>
#include <algorithm>
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

	sort(Sequence.begin(), Sequence.end());

	int Count = 0;
	for (int i = 0; i < N; ++i)
	{
		int Left = 0;
		int Right = N - 1;

		while (Left < Right)
		{
			if (Left == i)
			{
				++Left;
				continue;
			}

			if (Right == i)
			{
				--Right;
				continue;
			}

			int Sum = Sequence[Left] + Sequence[Right];

			if (Sum == Sequence[i])
			{
				++Count;
				break;
			}

			if (Sum > Sequence[i])
			{
				--Right;
			}
			else
			{
				++Left;
			}
		}
	}

	cout << Count;
}