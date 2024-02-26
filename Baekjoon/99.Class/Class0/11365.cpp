#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	while (true)
	{
		string Line;
		getline(cin, Line);
		
		if (Line.compare("END") == 0)
		{
			break;
		}

		reverse(Line.begin(), Line.end());
		cout << Line << '\n';
	}
}