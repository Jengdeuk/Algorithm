#include <iostream>
#include <string>
using namespace std;

bool Han[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	for (int i = 1; i <= 1000; ++i)
	{
		Han[i] = true;
	}

	for (int i = 100; i <= 1000; ++i)
	{
		string Num = to_string(i);
		int Pre = (Num[1] - '0') - (Num[0] - '0');
		for (int j = 2; j < Num.size(); ++j)
		{
			int Sub = (Num[j] - '0') - (Num[j - 1] - '0');
			if (Pre != Sub)
			{
				Han[i] = false;
				break;
			}
		}
	}

	int Cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (Han[i])
		{
			++Cnt;
		}
	}

	cout << Cnt;
}