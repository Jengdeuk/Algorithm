#include <iostream>
#include <string>
using namespace std;

int N, Q;
string T;

void Test()
{
	int Max = 0;
	for (int i = 1; i < T.size(); ++i)
	{
		int L = i - 1, R = i;
		
		int Cnt = 0;
		while (L >= 0 && R < T.size())
		{
			if (T[L--] == T[R++])
			{
				++Cnt;
			}
		}

		Max = max(Max, Cnt);
	}

	cout << Max << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> N >> S >> Q;
	for (int i = 0; i < Q; ++i)
	{
		int L, R;
		cin >> L >> R;
		T = S.substr(L - 1, R - L + 1);
		Test();
	}
}