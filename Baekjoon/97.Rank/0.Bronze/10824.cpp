#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string A, B, C, D;
	cin >> A >> B >> C >> D;
	A.append(B);
	C.append(D);
	cout << stoll(A) + stoll(C);
}