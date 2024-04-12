#include <iostream>
#include <algorithm>
using namespace std;

int N;
int IO[100001];
int PO[100001];

void Recursive(int IS, int IE, int PS, int PE)
{
	int Root = PO[PE];
	cout << Root << ' ';
	if (PS == PE)
	{
		return;
	}

	int IRIdx = find(IO + IS, IO + IE + 1, Root) - IO;
	int LeftNum = IRIdx - IS;
	int RightNum = IE - IRIdx;

	int RF = IO[IRIdx + 1];
	int PRFIdx = find(PO + PS, PO + PE + 1, RF) - PO;
	if (PE - PRFIdx < RightNum)
	{
		PRFIdx -= RightNum - (PE - PRFIdx);
	}

	if (PRFIdx - 1 >= PS && PRFIdx - 1 < PE)
	{
		Recursive(IS, IRIdx - 1, PS, PRFIdx - 1);
	}

	if (PRFIdx >= PS && PRFIdx < PE)
	{
		Recursive(IRIdx + 1, IE, PRFIdx, PE - 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		cin >> IO[i];
	}

	for (int i = 0; i < N; ++i)
	{
		cin >> PO[i];
	}

	Recursive(0, N - 1, 0, N - 1);
}