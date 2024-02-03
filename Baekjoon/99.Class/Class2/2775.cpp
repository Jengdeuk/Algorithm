#include <iostream>
#include <vector>
using namespace std;

const int& MaxSize = 14;
vector<vector<int>> Apartment;

void TestCase()
{
	int K, N;
	cin >> K >> N;

	for (int i = 0; i < N; ++i)
	{
		Apartment[0][i] = i + 1;
	}

	for (int i = 1; i <= K; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (Apartment[i][j] != 0)
			{
				continue;
			}

			for (int x = 0; x <= j; ++x)
			{
				Apartment[i][j] += Apartment[i - 1][x];
			}
		}
	}

	cout << Apartment[K][N - 1] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	Apartment.reserve(MaxSize + 1);
	for (int i = 0; i < MaxSize + 1; ++i)
	{
		Apartment.emplace_back(vector<int>(MaxSize, 0));
	}

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		TestCase();
	}
}