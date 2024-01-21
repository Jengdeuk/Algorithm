#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t = 0;
	cin >> t;

	vector<int> roomNumbers;
	roomNumbers.reserve(t);
	for (int i = 0; i < t; ++i)
	{
		int h = 0, w = 0, n = 0;
		cin >> h >> w >> n;

		int roomNumber = 1;
		for (int j = 0; j < n; ++j)
		{
			roomNumber += 100;
			if (roomNumber / 100 > h)
			{
				roomNumber -= h * 100;
				roomNumber += 1;
			}
		}

		roomNumbers.emplace_back(roomNumber);
	}

	for (const int& roomNumber : roomNumbers)
	{
		cout << roomNumber << "\n";
	}
}