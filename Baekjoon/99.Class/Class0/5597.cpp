#include <iostream>
using namespace std;

bool Student[31];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 28; ++i)
	{
		int Number;
		cin >> Number;
		Student[Number] = true;
	}

	for (int i = 1; i <= 30; ++i)
	{
		if (!Student[i])
		{
			cout << i << '\n';
		}
	}
}