#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string a, b;
	cin >> a >> b;

	ll sum = 0;
	for (int i = 0; i < a.size(); ++i)
		for (int j = 0; j < b.size(); ++j)
			sum += (a[i] - '0') * (b[j] - '0');

	cout << sum;
}