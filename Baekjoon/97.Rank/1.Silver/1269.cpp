#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> A;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int ANum, BNum;
	cin >> ANum >> BNum;

	for (int i = 0; i < ANum; ++i)
	{
		int Num;
		cin >> Num;
		++A[Num];
	}

	int Cnt = 0;
	for (int i = 0; i < BNum; ++i)
	{
		int Num;
		cin >> Num;
		if (A[Num] == 1)
		{
			++Cnt;
		}
	}
	
	cout << (ANum - Cnt) + (BNum - Cnt);
}