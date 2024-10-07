#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> p;
typedef pair<int, p> ip;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, M, F;
int Map[20][20];
p Dst[20][20];

bool IsValid(int R, int C)
{
	return (R >= 0 && R < N && C >= 0 && C < N && Map[R][C] >= 0);
}

bool Compare(const p& L, const p& R)
{
	return (L.first == R.first ? L.second < R.second : L.first < R.first);
}

ip BFS1(int SR, int SC)
{
	bool V[20][20] = {};

	queue<ip> Q;
	V[SR][SC] = true;
	Q.emplace(0, p(SR, SC));

	vector<p> Clients;
	int MinStep = 1000;
	while (!Q.empty())
	{
		int Step = Q.front().first;
		int R = Q.front().second.first;
		int C = Q.front().second.second;
		Q.pop();

		if (Map[R][C] > 0 && Step <= MinStep)
		{
			MinStep = Step;
			Clients.emplace_back(R, C);
		}
		else if (Map[R][C] > 0)
		{
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsValid(NR, NC) && !V[NR][NC])
			{
				V[NR][NC] = true;
				Q.emplace(Step + 1, p(NR, NC));
			}
		}
	}

	if (Clients.empty())
	{
		return ip(-1, p(0, 0));
	}

	sort(Clients.begin(), Clients.end(), Compare);

	return ip(MinStep, p(Clients.front().first, Clients.front().second));
}

int BFS2(int SR, int SC, int DR, int DC)
{
	bool V[20][20] = {};

	queue<ip> Q;
	V[SR][SC] = true;
	Q.emplace(0, p(SR, SC));
	while (!Q.empty())
	{
		int Step = Q.front().first;
		int R = Q.front().second.first;
		int C = Q.front().second.second;
		Q.pop();

		if (R == DR && C == DC)
		{
			return Step;
		}

		for (int i = 0; i < 4; ++i)
		{
			int NR = R + DY[i];
			int NC = C + DX[i];
			if (IsValid(NR, NC) && !V[NR][NC])
			{
				V[NR][NC] = true;
				Q.emplace(Step + 1, p(NR, NC));
			}
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> F;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			bool bWall;
			cin >> bWall;
			if (bWall)
			{
				Map[i][j] = -1;
			}
		}
	}

	int R, C;
	cin >> R >> C;
	--R, --C;
	for (int i = 1; i <= M; ++i)
	{
		int SR, SC, DR, DC;
		cin >> SR >> SC >> DR >> DC;
		Map[SR - 1][SC - 1] = i;
		Dst[SR - 1][SC - 1] = p(DR - 1, DC - 1);
	}

	int Count = M;
	while (Count > 0 && F > 0)
	{
		ip ToClient = BFS1(R, C);

		int Step = ToClient.first;
		F -= Step;
		if (Step == -1 || F <= 0)
		{
			break;
		}

		int SR = ToClient.second.first;
		int SC = ToClient.second.second;
		R = SR, C = SC;
		Map[R][C] = 0;

		int DR = Dst[SR][SC].first;
		int DC = Dst[SR][SC].second;
		Step = BFS2(SR, SC, DR, DC);
		F -= Step;
		if (Step == -1 || F < 0)
		{
			break;
		}

		F += 2 * Step;
		R = DR, C = DC;
		--Count;
	}

	if (Count == 0)
	{
		cout << F;
	}
	else
	{
		cout << -1;
	}
}