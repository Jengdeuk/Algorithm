#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	cin.get();
	for (int i = 1; i <= N; ++i)
	{
		string S;
		getline(cin, S);
		cout << i << ". " << S << '\n';
	}
}