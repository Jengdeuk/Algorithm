#include <iostream>
#include <string>
using namespace std;

void Test()
{
	string Input;
	cin >> Input;

	cout << Input.front() << Input.back() << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}