#include <iostream>
#include <string>
using namespace std;

string Result;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, B;
	cin >> N >> B;

	while (N != 0)
	{
		int Num = N % B;
		N /= B;
		if (Num >= 10)
		{
			Result.push_back(char(Num - 10 + 'A'));
		}
		else
		{
			Result.push_back(char(Num + '0'));
		}
	}

	for (int i = Result.size() - 1; i >= 0; --i)
	{
		cout << Result[i];
	}
}