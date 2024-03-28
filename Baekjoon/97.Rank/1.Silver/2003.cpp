#include <iostream>
using namespace std;

int Seq[10001];
int Sum[10001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		cin >> Seq[i];
		Sum[i] = Sum[i - 1] + Seq[i];
	}

	int Cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = i; j <= N; ++j)
		{
			if (Sum[j] - Sum[i - 1] == M)
			{
				++Cnt;
			}
		}
	}

	cout << Cnt;
}