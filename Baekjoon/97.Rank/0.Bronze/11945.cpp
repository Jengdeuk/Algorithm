#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		reverse(S.begin(), S.end());
		cout << S << '\n';
	}
}