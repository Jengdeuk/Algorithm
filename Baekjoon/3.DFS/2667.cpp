#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int Complex = 0;
vector<int> Map;
vector<vector<int>> Neighbors;
vector<int> Households;

int NumberingComplex(int HouseIndex)
{
	int Count = 1;
	Map[HouseIndex] = Complex;

	for (int& Neighbor : Neighbors[HouseIndex])
	{
		if (Map[Neighbor] == 0)
		{
			Count += NumberingComplex(Neighbor);
		}
	}

	return Count;
}

int main()
{
	int n;
	cin >> n;

	Map.reserve(n * n);
	for (int i = 0; i < n * n; ++i)
	{
		char Character = cin.get();
		if (Character == '\n') Character = cin.get();
		Map.emplace_back(Character - '0' - 1);
	}

	Neighbors.reserve(n);
	for (int i = 0; i < n * n; ++i)
	{
		Neighbors.emplace_back(vector<int>());
	}

	int i = 0;
	for (const int& House : Map)
	{
		if (House == 0)
		{
			// top
			if (i / n > 0 && i - n >= 0
				&& Map[i - n] == 0)
			{
				Neighbors[i].emplace_back(i - n);
			}

			// bottom
			if (i / n < n - 1 && i + n < n * n
				&& Map[i + n] == 0)
			{
				Neighbors[i].emplace_back(i + n);
			}

			// left
			if (i % n > 0 && i - 1 >= 0
				&& Map[i - 1] == 0)
			{
				Neighbors[i].emplace_back(i - 1);
			}

			// right
			if (i % n < n - 1 && i + 1 < n * n
				&& Map[i + 1] == 0)
			{
				Neighbors[i].emplace_back(i + 1);
			}
		}

		++i;
	}

	i = 0;
	for (const int& House : Map)
	{
		if (House == 0)
		{
			++Complex;
			Households.emplace_back(NumberingComplex(i));
		}

		++i;
	}

	sort(Households.begin(), Households.end());

	cout << Complex << '\n';
	for (const int& Household : Households)
	{
		cout << Household << '\n';
	}
}