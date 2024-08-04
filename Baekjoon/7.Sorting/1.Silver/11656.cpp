#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string L[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;
	N = S.size();
	for (int i = 0; i < N; ++i)
	{
		L[i] = S.substr(i, N - i);
	}

	sort(L, L + N);

	for (int i = 0; i < N; ++i)
	{
		cout << L[i] << '\n';
	}
}