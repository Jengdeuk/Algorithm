#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string Input;
	while (true)
	{
		getline(cin, Input);
		if (Input == "")
		{
			break;
		}

		cout << Input << '\n';
	}
}