#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	string S;
	cin >> S;

	string A;
	for (int i = 0; i < N; ++i)
	{
		int AS = A.size();
		if (AS >= 2 && A[AS - 2] == 'P' && A[AS - 1] == 'S'
			&& (S[i] == '4' || S[i] == '5'))
		{
			continue;
		}

		A.push_back(S[i]);
	}

	cout << A;
}