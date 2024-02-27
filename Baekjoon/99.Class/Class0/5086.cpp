#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		int A, B;
		cin >> A >> B;

		if (A == 0 && B == 0)
		{
			break;
		}

		if (B % A == 0)
		{
			cout << "factor\n";
		}
		else if (A % B == 0)
		{
			cout << "multiple\n";
		}
		else
		{
			cout << "neither\n";
		}
	}
}