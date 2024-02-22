#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int Sum = 0;
	for (int i = 0; i < 4; ++i)
	{
		int Second;
		cin >> Second;
		Sum += Second;
	}

	cout << Sum / 60 << '\n';
	cout << Sum % 60;
}