#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int E, S, M;
	cin >> E >> S >> M;

	int Year = 1;
	int e = 1, s = 1, m = 1;
	while (e != E || s != S || m != M)
	{
		++Year;
		e = (e + 1 > 15) ? 1 : e + 1;
		s = (s + 1 > 28) ? 1 : s + 1;
		m = (m + 1 > 19) ? 1 : m + 1;
	}

	cout << Year;
}