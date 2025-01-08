#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string A, B;
	cin >> A >> B;

	int CA[26] = {};
	for (const char a : A)
	{
		++CA[a - 'a'];
	}

	int CB[26] = {};
	for (const char b : B)
	{
		++CB[b - 'a'];
	}

	int Cnt = 0;
	for (int i = 0; i < 26; ++i)
	{
		Cnt += abs(CA[i] - CB[i]);
	}

	cout << Cnt;
}