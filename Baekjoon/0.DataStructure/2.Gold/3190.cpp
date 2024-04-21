#include <iostream>
#include <deque>
using namespace std;

typedef pair<int, int> p;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

int N, K, L;
int Map[100][100];
p Change[100];
deque<p> Snake;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < K; ++i)
	{
		int R, C;
		cin >> R >> C;
		Map[R - 1][C - 1] = 2;
	}

	cin >> L;
	for (int i = 0; i < L; ++i)
	{
		int X;
		char C;
		cin >> X >> C;
		Change[i].first = X;
		Change[i].second = (C == 'L') ? -1 : 1;
	}

	Snake.push_back(p(0, 0));
	int Time = 0, Li = 0, Di = 2;
	while (true)
	{
		++Time;

		int R = Snake.back().first;
		int C = Snake.back().second;

		int NR = R + DY[Di];
		int NC = C + DX[Di];
		if (NR < 0 || NR > N - 1 || NC < 0 || NC > N - 1 || Map[NR][NC] == 1)
		{
			break;
		}

		if (Map[NR][NC] != 2)
		{
			int FR = Snake.front().first;
			int FC = Snake.front().second;
			Snake.pop_front();
			Map[FR][FC] = 0;
		}

		Map[NR][NC] = 1;
		Snake.push_back(p(NR, NC));

		if (Li != L && Time == Change[Li].first)
		{
			int ND = Di + Change[Li].second;
			Di = (ND < 0) ? 3 : ((ND > 3) ? 0 : ND);
			++Li;
		}
	}

	cout << Time;
}