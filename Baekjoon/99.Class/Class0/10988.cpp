#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string Input;
	cin >> Input;
	string Reverse = Input;
	reverse(Reverse.begin(), Reverse.end());
	cout << (Input.compare(Reverse) == 0);
}