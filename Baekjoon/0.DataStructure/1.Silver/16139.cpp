#include <iostream>
#include <string>
using namespace std;

int sum[26][200001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string s;
	cin >> s;

	for (int i = 0; i < 26; ++i)
	{
		char a = 'a' + i;
		for (int j = 0; j < s.size(); ++j)
		{
			sum[i][j + 1] = sum[i][j] + (s[j] == a);
		}
	}

	int q;
	cin >> q;
	while (q--)
	{
		char a;
		cin >> a;

		int l, r;
		cin >> l >> r;
		cout << sum[a - 'a'][r + 1] - sum[a - 'a'][l] << '\n';
	}
}