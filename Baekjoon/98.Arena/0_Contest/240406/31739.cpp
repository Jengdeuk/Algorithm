#include <iostream>
#include <cstring>
using namespace std;

typedef pair<int, int> p;

int N, M, K, T, P;
pair<int, p> MP[10];

int Max;
int Way[10];
bool Check[10];
void Backtracking(int Idx)
{
	if (Idx == K)
	{
		int Time = 0, Kill = 1;
		int R = MP[Way[0]].second.first;
		int C = MP[Way[0]].second.second;
		for (int i = 1; i < K; ++i)
		{
			int NR = MP[Way[i]].second.first;
			int NC = MP[Way[i]].second.second;
			Time += abs(NR - R) + abs(NC - C);
			if (Time > T)
			{
				break;
			}

			++Kill;
			R = NR;
			C = NC;
		}

		Max = max(Max, Kill);
		return;
	}

	for (int i = 0; i < K; ++i)
	{
		if (Check[i])
		{
			continue;
		}

		Check[i] = true;
		Way[Idx] = i;
		Backtracking(Idx + 1);
		Check[i] = false;
	}
}

int ElectricField(int SR, int SC)
{
	int Kill = 0;

	for (int i = 0; i < K; ++i)
	{
		int S = MP[i].first;
		int R = MP[i].second.first;
		int C = MP[i].second.second;
		int L = abs(R - SR) + abs(C - SC);
		if (L == 0 || P / L >= S)
		{
			++Kill;
		}
	}

	return Kill;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K >> T >> P;

	for (int i = 0; i < K; ++i)
	{
		int R, C, S;
		cin >> R >> C >> S;
		MP[i].first = S;
		MP[i].second = p(R, C);
	}

	int Woo = 0;
	Backtracking(0);
	Woo = max(Woo, Max);

	int Arm = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= M; ++j)
		{
			Arm = max(Arm, ElectricField(i, j));
		}
	}

	cout << Woo << ' ' << Arm;
}