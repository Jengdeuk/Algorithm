#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> Closet;

void TestCase()
{
	Closet.clear();

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string First, Second;
		cin >> First >> Second;
		++Closet[Second];
	}

	int Case = 1;
	for (const pair<string, int>& Clothes : Closet)
	{
		Case *= (Clothes.second + 1);
	}
	cout << Case - 1 << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		TestCase();
	}
}