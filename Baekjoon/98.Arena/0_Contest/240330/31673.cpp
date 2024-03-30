#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
int Num[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	ll People = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> Num[i];
		People += Num[i];
	}

	sort(Num, Num + N, greater<>());

	ll Cnt = 0;
	ll Select = 0;
	ll Half = People / 2;
	for (int i = 0; i < N; ++i)
	{
		if (People - Select > Half)
		{
			Select += Num[i];
			++Cnt;
		}
		else
		{
			break;
		}
	}

	cout << M / (Cnt + 1);
}