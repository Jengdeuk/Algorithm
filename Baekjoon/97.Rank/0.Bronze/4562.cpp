#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int A, B;
		cin >> A >> B;
		if (A < B)
		{
			cout << "NO BRAINS\n";
		}
		else
		{
			cout << "MMM BRAINS\n";
		}
	}
}