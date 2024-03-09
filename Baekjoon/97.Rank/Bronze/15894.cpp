#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	long long Result = N;
	Result += N;
	Result += N;
	Result += N;
	cout << Result;
}