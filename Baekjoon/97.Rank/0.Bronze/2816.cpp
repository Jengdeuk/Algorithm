#include <iostream>
#include <string>
using namespace std;

int n, k1i, k2i;
string chs[100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> chs[i];
		if (chs[i].compare("KBS1") == 0)
			k1i = i;
		else if (chs[i].compare("KBS2") == 0)
			k2i = i;
	}

	for (int i = 0; i < k1i; ++i)
		cout << 1;

	for (int i = 0; i < k1i; ++i)
		cout << 4;

	for (int i = 0; i < k2i + (k2i < k1i); ++i)
		cout << 1;

	for (int i = 0; i < k2i + (k2i < k1i) - 1; ++i)
		cout << 4;
}