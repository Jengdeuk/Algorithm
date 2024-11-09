#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	if (M <= 2)
	{
		cout << "NEWBIE!";
	}
	else if (M <= N)
	{
		cout << "OLDBIE!";
	}
	else
	{
		cout << "TLE!";
	}
}