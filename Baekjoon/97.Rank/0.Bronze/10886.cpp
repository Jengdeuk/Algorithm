#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		int Vote;
		cin >> Vote;
		Cnt += Vote;
	}

	if (Cnt < ceil(float(N) / 2))
	{
		cout << "Junhee is not cute!";
	}
	else
	{
		cout << "Junhee is cute!";
	}
}