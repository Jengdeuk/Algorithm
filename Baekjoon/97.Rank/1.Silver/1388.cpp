#include <iostream>
using namespace std;

int N, M;
char F[50][50];
bool V[50][50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			cin >> F[i][j];
		}
	}

	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (V[i][j])
			{
				continue;
			}

			Cnt++;
			V[i][j] = true;
			if (F[i][j] == '-')
			{
				int NC = j + 1;
				while (NC < M && F[i][NC] == '-')
				{
					V[i][NC] = true;
					NC++;
				}
			}
			else
			{
				int NR = i + 1;
				while (NR < N && F[NR][j] == '|')
				{
					V[NR][j] = true;
					NR++;
				}
			}
		}
	}

	cout << Cnt;
}