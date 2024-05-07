#include <iostream>
#include <algorithm>
using namespace std;

int N;
int Seq[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Seq[i];
	}

	bool bFind = false;
	for (int i = N - 1; i > 0; --i)
	{
		if (Seq[i - 1] < Seq[i])
		{
			bFind = true;
			sort(Seq + i, Seq + N);
			int Index = lower_bound(Seq + i, Seq + N, Seq[i - 1] + 1) - Seq;
			int Temp = Seq[i - 1];
			Seq[i - 1] = Seq[Index];
			Seq[Index] = Temp;
			break;
		}
	}

	if (bFind)
	{
		for (int i = 0; i < N; ++i)
		{
			cout << Seq[i] << ' ';
		}
	}
	else
	{
		cout << -1;
	}
}