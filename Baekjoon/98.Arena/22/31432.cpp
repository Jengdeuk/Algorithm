#include <iostream>
#include <string>
using namespace std;

int N;
bool Valid[10];
bool bFound;
string Solution;

bool Check(string Current)
{
	int CurNum = stoi(Current);

	if (CurNum == 0 || CurNum == 1)
	{
		cout << "YES\n" << CurNum;
		return true;
	}

	for (int i = 2; i < CurNum; ++i)
	{
		if (CurNum % i == 0)
		{
			cout << "YES\n" << CurNum;
			return true;
		}
	}

	return false;
}

void DFS()
{
	Solution.push_back('0');
	int CurSize = Solution.size();

	if (CurSize > 12 || bFound)
	{
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		if (bFound)
		{
			return;
		}

		if (!Valid[i])
		{
			continue;
		}

		Solution[CurSize - 1] = i + '0';
		if (Check(Solution))
		{
			bFound = true;
			return;
		}

		DFS();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Number;
		cin >> Number;
		Valid[Number] = true;
	}

	DFS();

	if (!bFound)
	{
		cout << "NO";
	}
}