#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int S, K, H;
	cin >> S >> K >> H;
	if (S + K + H >= 100)
	{
		cout << "OK";
	}
	else
	{
		int Min = min(S, min(K, H));
		if (Min == S)
		{
			cout << "Soongsil";
		}
		else if (Min == K)
		{
			cout << "Korea";
		}
		else
		{
			cout << "Hanyang";
		}
	}
}