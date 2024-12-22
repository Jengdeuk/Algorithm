#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MaxSum = 1000000000;

int N, C;
int W[30];

vector<int> Left;
vector<int> Right;

void BTL(int Idx, int Sum)
{
	if (Idx == N / 2)
	{
		Left.emplace_back(Sum);
		return;
	}

	long long New = Sum + W[Idx];
	if (New <= MaxSum)
	{
		BTL(Idx + 1, New);
	}

	BTL(Idx + 1, Sum);
}

void BTR(int Idx, int Sum)
{
	if (Idx == N)
	{
		Right.emplace_back(Sum);
		return;
	}

	long long New = Sum + W[Idx];
	if (New <= MaxSum)
	{
		BTR(Idx + 1, New);
	}

	BTR(Idx + 1, Sum);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> C;
	for (int i = 0; i < N; ++i)
	{
		cin >> W[i];
	}

	BTL(0, 0);
	BTR(N / 2, 0);

	sort(Right.begin(), Right.end());

	long long Cnt = 0;
	for (int i = 0; i < Left.size(); ++i)
	{
		int LS = Left[i];
		int Capa = C - LS;
		Cnt += upper_bound(Right.begin(), Right.end(), Capa) - Right.begin();
	}

	cout << Cnt;
}