#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string A, B;
	cin >> A >> B;

	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	int N = stoi(A) + stoi(B);
	string NS = to_string(N);
	reverse(NS.begin(), NS.end());

	cout << stoi(NS);
}