#include <iostream>
#include <string>
using namespace std;

void Test()
{
	int N, M;
	cin >> N >> M;

	int C = N;
	int Count = 0;
	while (C <= M)
	{
		string S = to_string(C);
		for (int i = 0; i < S.size(); ++i)
		{
			if (S[i] == '0')
			{
				++Count;
			}
		}

		++C;
	}

	cout << Count << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}