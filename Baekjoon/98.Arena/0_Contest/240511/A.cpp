#include <iostream>
using namespace std;

int Sum[100001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	
	int Cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		int Num;
		cin >> Num;
		Sum[i] = (Sum[i - 1] + Num < 0 ? 0 : Sum[i - 1] + Num);
		if (Sum[i] >= M)
		{
			++Cnt;
		}
	}

	cout << Cnt;
}