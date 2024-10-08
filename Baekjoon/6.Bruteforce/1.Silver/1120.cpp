#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string A, B;
	cin >> A >> B;

	int Min = 50;
	for (int i = 0; i + A.size() <= B.size(); ++i)
	{
		int Count = 0;
		for (int j = 0; j < A.size(); ++j)
		{
			if (A[j] != B[i + j])
			{
				++Count;
			}
		}

		Min = min(Min, Count);
	}

	cout << Min;
}