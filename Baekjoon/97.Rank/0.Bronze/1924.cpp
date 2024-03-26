#include <iostream>
#include <string>
using namespace std;

const string Week[7] =
{
	"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"
};

const int Month[12] =
{
	0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int X, Y;
	cin >> X >> Y;

	cout << Week[(Month[X - 1] + Y - 1) % 7];
}