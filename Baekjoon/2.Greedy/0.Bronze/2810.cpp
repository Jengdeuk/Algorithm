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

	int Count = 1;
	for (int i = 0; i < N; ++i)
	{
		++Count;

		if (S[i] == 'L')
		{
			++i;
		}
	}

	cout << min(N, Count);
}