#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Cur = 0, Max = 0;
	for (int i = 0; i < 10; ++i)
	{
		int Out, In;
		cin >> Out >> In;

		Cur = Cur - Out + In;
		Max = max(Max, Cur);
	}

	cout << Max;
}