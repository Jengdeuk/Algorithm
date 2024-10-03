#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		for (int j = 0; j < S.size(); ++j)
		{
			if (S[j] < 'a')
			{
				S[j] = S[j] - 'A' + 'a';
			}
		}
		cout << S << '\n';
	}
}