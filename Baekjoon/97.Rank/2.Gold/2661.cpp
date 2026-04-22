#include <iostream>
#include <string>
using namespace std;

bool bHasFinished;
int N;
string S;

bool IsValid()
{
	int CurN = S.size();
	int Len = 1;
	while (Len * 2 <= CurN)
	{
		int R = CurN - 1 - Len + 1;
		int L = CurN - 1 - Len - Len + 1;
		if ((S.substr(R, Len)).compare(S.substr(L, Len)) == 0)
		{
			return false;
		}

		++Len;
	}

	return true;
}

void BT(int Idx)
{
	if (Idx == N)
	{
		bHasFinished = true;
		return;
	}

	for (int j = 1; j <= 3; ++j)
	{
		S.push_back(j + '0');
		if (IsValid())
		{
			BT(Idx + 1);
			if (bHasFinished)
			{
				return;
			}
		}

		S.pop_back();
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;

	BT(0);

	cout << S;
}