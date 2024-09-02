#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int PM = 1000, OM = 1000;
	for (int i = 0; i < M; ++i)
	{
		int P, O;
		cin >> P >> O;
		PM = min(PM, P);
		OM = min(OM, O);
	}

	int AllP = (N / 6 + (N % 6 > 0 ? 1 : 0)) * PM;
	int AllO = N * OM;
	int PO = N / 6 * PM + N % 6 * OM;
	cout << min(AllP, min(AllO, PO));
}