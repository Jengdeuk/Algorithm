#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	cin.ignore();

	for (int i = 0; i < T; ++i)
	{
		string Str;
		getline(cin, Str);
		
		int S = 0, E = Str.size();
		for (int i = 0; i < Str.size(); ++i)
		{
			if (Str[i] == ' ')
			{
				E = i;
				for (int j = E - 1; j >= S; --j)
				{
					cout << Str[j];
				}
				cout << ' ';

				S = i + 1;
			}

			E = Str.size();
		}

		for (int j = E - 1; j >= S; --j)
		{
			cout << Str[j];
		}
		cout << '\n';
	}
}