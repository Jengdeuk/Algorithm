#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, B, C;
	cin >> A >> B >> C;

	int TA = A, TB = B;
	A = max(TA, TB);
	B = min(TA, TB);
	
	int TTA = A, TC = C;
	A = max(TTA, TC);
	C = min(TTA, TC);

	while (A >= B + C)
	{
		--A;
	}

	cout << A + B + C;
}