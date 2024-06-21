#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

const ll Max = pow(ll(2), ll(60));
const ll Mul = 1000'00000'00000'00000;

void PrintNum(ll N)
{
	ll Bit = Max;

	ll Floor = 61;
	while (!(N & Bit))
	{
		Bit >>= 1;
		--Floor;
	}
	cout << Floor;

	ll Room = N - Bit + 1;

	ll Temp = Room;
	ll Digit = 1;
	while (Temp / 10 > 0)
	{
		++Digit;
		Temp /= 10;
	}

	for (int i = 0; i < 18 - Digit; ++i)
	{
		cout << 0;
	}

	cout << Room;
	cout << '\n';
}

void Test()
{
	ll N;
	cin >> N;

	while (N >= 1)
	{
		PrintNum(N);
		N >>= 1;
	}
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