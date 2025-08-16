#include <iostream>
#include <algorithm>
using namespace std;

int N, C[50], M, B[10000];

bool V[10000];
int CI[50];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> C[i];
	}

	sort(C, C + N, greater<>());

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> B[i];
	}

	sort(B, B + M, greater<>());

	int Time = 0;
	bool bContinue = true;
	while (bContinue)
	{
		Time++;
		bContinue = false;

		for (int i = 0; i < N; ++i)
		{
			for (int j = CI[i]; j < M; ++j)
			{
				CI[i] = j + 1;

				if (V[j] == false && C[i] >= B[j])
				{
					bContinue = true;
					V[j] = true;
					break;
				}
			}
		}
	}

	bool bFinished = true;
	for (int i = 0; i < M; ++i)
	{
		if (V[i] == false)
		{
			bFinished = false;
			break;
		}
	}

	if (bFinished)
	{
		cout << Time - 1;
	}
	else
	{
		cout << -1;
	}
}