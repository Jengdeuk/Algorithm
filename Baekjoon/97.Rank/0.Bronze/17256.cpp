#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int AX, AY, AZ, CX, CY, CZ;
	cin >> AX >> AY >> AZ >> CX >> CY >> CZ;
	cout << CX - AZ << ' ' << CY / AY << ' ' << CZ - AX;
}