#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, string> Passwords;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string URL, PW;
		cin >> URL >> PW;
		Passwords[URL] = PW;
	}

	for (int i = 0; i < M; ++i)
	{
		string URL;
		cin >> URL;
		cout << Passwords[URL] << '\n';
	}
}