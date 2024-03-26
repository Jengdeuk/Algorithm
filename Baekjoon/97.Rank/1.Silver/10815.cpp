#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> HashTable;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;
		++HashTable[Num];
	}

	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		int Num;
		cin >> Num;
		cout << HashTable[Num] << ' ';
	}
}