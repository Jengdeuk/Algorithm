#include <iostream>
#include <string>
#include <cstring>
#include <list>
#include <vector>
#include <cmath>
using namespace std;

const int DX[4] = { 1, 0, -1, 0 };
const int DY[4] = { 0, 1, 0, -1 };

string S;
int N, M;
int Map[21][21];
bool Visited[21][21];

bool DontGo(int R, int C)
{
	for (int i = 0; i < 4; ++i)
	{
		int NR = R + DY[i];
		int NC = C + DX[i];
		if (NR >= 0 && NR <= N - 1 && NC >= 0 && NC <= M - 1 && !Visited[NR][NC])
		{
			return false;
		}
	}

	return true;
}

void Search()
{
	list<vector<int>> Digit;
	int Cnt = 0;
	vector<int> Temp(5);
	int R = 0, C = 0, D = 0;
	while (true)
	{
		Visited[R][C] = true;

		Temp[Cnt] = Map[R][C];
		++Cnt;
		if (Cnt == 5)
		{
			Digit.emplace_back(Temp);
			Cnt = 0;
		}

		int NR = R + DY[D];
		int NC = C + DX[D];
		if (DontGo(R, C))
		{
			break;
		}
		else if (NR < 0 || NR > N - 1 || NC < 0 || NC > M - 1 || Visited[NR][NC])
		{
			D = (D + 1 == 4 ? 0 : D + 1);
			NR = R + DY[D];
			NC = C + DX[D];
		}
		R = NR, C = NC;
	}

	string Print;
	for (const vector<int>& DG : Digit)
	{
		int Num = 0;
		for (int i = 0; i < 5; ++i)
		{
			Num += pow((int)2, i) * DG[4 - i];
		}

		if (Num == 0)
		{
			Print.push_back(' ');
		}
		else
		{
			Print.push_back(char(Num + 64));
		}
	}

	int StartIndex = 0;
	for (int i = 0; i < Print.size(); ++i)
	{
		if (Print[i] == ' ')
		{
			++StartIndex;
		}
		else
		{
			break;
		}
	}

	for (int i = Print.size() - 1; i >= 0; --i)
	{
		if (Print[i] == ' ')
		{
			Print.pop_back();
		}
		else
		{
			break;
		}
	}

	for (int i = StartIndex; i < Print.size(); ++i)
	{
		cout << Print[i];
	}

	cout << '\n';
}

void Test()
{
	cin >> N >> M >> S;

	memset(Visited, false, sizeof(Visited));
	for (int i = 0; i < S.size(); ++i)
	{
		Map[i / M][i % M] = S[i] - '0';
	}

	Search();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}