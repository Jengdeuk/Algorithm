#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		string Line;
		cin >> Line;

		int Comma = Line.find(',');
		string A = Line.substr(0, Comma);
		string B = Line.substr(Comma + 1);
		cout << stoi(A) + stoi(B) << '\n';
	}
}