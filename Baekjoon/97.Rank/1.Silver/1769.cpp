#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;

	int Cnt = 0;
	while (S.size() > 1)
	{
		int Sum = 0;
		for (const char Ch : S)
		{
			Sum += Ch - '0';
		}

		S = to_string(Sum);
		Cnt++;
	}

	cout << Cnt << '\n';
	if ((S.front() - '0') % 3 == 0)
	{
		cout << "YES";
	}
	else
	{
		cout << "NO";
	}
}