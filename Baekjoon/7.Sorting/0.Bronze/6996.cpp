#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void Print(bool bAnagram, string A, string B)
{
	cout << A << " & " << B << " are ";
	if (!bAnagram)
	{
		cout << "NOT ";
	}
	cout << "anagrams.\n";
}

void Test()
{
	string A, B;
	cin >> A >> B;

	int AN = A.size();
	int BN = B.size();
	if (AN != BN)
	{
		Print(false, A, B);
		return;
	}

	string AS = A, BS = B;
	sort(AS.begin(), AS.end());
	sort(BS.begin(), BS.end());
	for (int i = 0; i < AN; ++i)
	{
		if (AS[i] != BS[i])
		{
			Print(false, A, B);
			return;
		}
	}

	Print(true, A, B);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}