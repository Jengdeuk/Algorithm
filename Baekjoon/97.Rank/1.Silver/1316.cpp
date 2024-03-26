#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int Cnt = N;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;

		bool Alpha[26];
		memset(Alpha, false, sizeof(Alpha));

		int Pre = -1;
		for (int j = 0; j < str.size(); ++j)
		{
			int Current = str[j] - 'a';
			if (Alpha[Current] && Current != Pre)
			{
				--Cnt;
				break;
			}

			Alpha[Current] = true;
			Pre = Current;
		}
	}

	cout << Cnt;
}