#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string Line;
	cin >> Line;

	int Cnt = 0;
	for (int i = 0; i < Line.size(); ++i)
	{
		cout << Line[i];

		++Cnt;
		if (Cnt == 10)
		{
			Cnt = 0;
			cout << '\n';
		}
	}
}