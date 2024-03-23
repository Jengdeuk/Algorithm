#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pos;

const long long Infinite = LLONG_MAX;

int MX, MY, A, KX, KY, B, M, K;
pos MP[1002001], KP[1002001];

int MCX, MCY, KCX, KCY;
ll Min = Infinite;
pos MM, MK;

void CompareRect()
{
	if (MX + A < KX)
	{
		MCX = MX + A;
		KCX = KX;
	}
	else if (KX + B < MX)
	{
		MCX = MX;
		KCX = KX + B;
	}
	else if (MX <= KX && KX <= MX + A)
	{
		MCX = KX;
		KCX = KX;
	}
	else
	{
		MCX = KX + B;
		KCX = KX + B;
	}

	if (MY + A < KY)
	{
		MCY = MY + A;
		KCY = KY;
	}
	else if (KY + B < MY)
	{
		MCY = MY;
		KCY = KY + B;
	}
	else if (MY <= KY && KY <= MY + A)
	{
		MCY = KY;
		KCY = KY;
	}
	else
	{
		MCY = KY + B;
		KCY = KY + B;
	}
}

bool compMCX(const pos& Left, const pos& Right)
{
	return abs(Left.first - MCX) < abs(Right.first - MCX);
}

bool compKCX(const pos& Left, const pos& Right)
{
	return abs(Left.first - KCX) < abs(Right.first - KCX);
}

bool compMCY(const pos& Left, const pos& Right)
{
	return abs(Left.second - MCY) < abs(Right.second - MCY);
}

bool compKCY(const pos& Left, const pos& Right)
{
	return abs(Left.second - KCY) < abs(Right.second - KCY);
}

ll Distance(const pos& Left, const pos& Right)
{
	ll DX = Left.first - Right.first;
	ll DY = Left.second - Right.second;
	return DX * DX + DY * DY;
}

void SearchMinDistance()
{
	for (int i = 0; i < min(M, 1000); ++i)
	{
		for (int j = 0; j < min(K, 1000); ++j)
		{
			ll D = Distance(MP[i], KP[j]);
			if (D < Min)
			{
				Min = D;
				MM = MP[i];
				MK = KP[j];
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> MX >> MY >> A >> KX >> KY >> B >> M >> K;

	for (int i = 0; i < M; ++i)
	{
		cin >> MP[i].first >> MP[i].second;
	}

	for (int i = 0; i < K; ++i)
	{
		cin >> KP[i].first >> KP[i].second;
	}

	CompareRect();

	sort(MP, MP + M, compMCX);
	sort(KP, KP + K, compKCX);
	SearchMinDistance();

	sort(MP, MP + M, compMCY);
	sort(KP, KP + K, compKCY);
	SearchMinDistance();

	cout << Min << '\n';
	cout << MM.first << ' ' << MM.second << '\n';
	cout << MK.first << ' ' << MK.second;
}