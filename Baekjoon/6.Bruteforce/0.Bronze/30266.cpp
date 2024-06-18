#include <iostream>
#include <string>
using namespace std;

void Test(int T)
{
	int N;
	cin >> N;

	string M;
	cin >> M;

	bool C[26] = {};
	for (int i = 0; i < M.size(); ++i)
	{
		C[M[i] - 'A'] = true;
	}

	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		for (int j = 0; j < S.size(); ++j)
		{
			if (C[S[j] - 'A'])
			{
				++Cnt;
				break;
			}
		}
	}

	cout << "Data Set " << T << ":\n";
	cout << Cnt << "\n\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int K;
	cin >> K;
	for (int i = 1; i <= K; ++i)
	{
		Test(i);
	}
}