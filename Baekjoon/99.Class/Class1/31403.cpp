#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string A, B, C;
	cin >> A >> B >> C;

	cout << stoi(A) + stoi(B) - stoi(C) << '\n';
	cout << stoi(A.append(B)) - stoi(C);
}