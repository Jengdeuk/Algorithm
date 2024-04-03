#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string A, B;
	cin >> A >> B;
	if (A.size() >= B.size())
	{
		cout << "go";
	}
	else
	{
		cout << "no";
	}
}