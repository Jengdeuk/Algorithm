#include <iostream>
using namespace std;

typedef pair<int, int> p;

int CCW(p A, p B, p C)
{
	int AX = A.first, AY = A.second, BX = B.first, BY = B.second, CX = C.first, CY = C.second;
	return AX * BY + BX * CY + CX * AY - (BX * AY + CX * BY + AX * CY);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	p A, B, C;
	cin >> A.first >> A.second >> B.first >> B.second >> C.first >> C.second;

	int Result = CCW(A, B, C);
	if (Result > 0)
	{
		cout << 1;
	}
	else if (Result < 0)
	{
		cout << -1;
	}
	else
	{
		cout << 0;
	}
}