#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Size = 3;

vector<int> Numbers;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	Numbers.reserve(Size);
	for (int i = 0; i < Size; ++i)
	{
		int Number;
		cin >> Number;
		Numbers.emplace_back(Number);
	}

	sort(Numbers.begin(), Numbers.end());

	for (const int& Number : Numbers)
	{
		cout << Number << ' ';
	}
}