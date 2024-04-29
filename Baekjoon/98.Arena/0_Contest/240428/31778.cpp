#include <iostream>
#include <string>
using namespace std;

typedef long long ll;

int N, K;
string PPC;
int NumP[200000];
int NumC[200000];

void Init()
{
	cin >> N >> K >> PPC;
}

void MakePPC()
{
	int S = 0, E = N - 1;
	bool bRepeat = true;
	while (bRepeat && K > 0)
	{
		bRepeat = false;

		for (int j = S; j < E; ++j)
		{
			if (PPC[j] == 'C')
			{
				for (int k = E; k > j; --k)
				{
					if (PPC[k] == 'P')
					{
						bRepeat = true;
						--K;

						PPC[j] = 'P';
						PPC[k] = 'C';

						S = j;
						E = k;

						j = E;
						break;
					}
				}
				break;
			}
		}
	}

	for (int i = 1; i < N; ++i)
	{
		NumP[i] = NumP[i - 1] + (PPC[i - 1] == 'P' ? 1 : 0);
	}

	for (int i = N - 2; i >= 0; --i)
	{
		NumC[i] = NumC[i + 1] + (PPC[i + 1] == 'C' ? 1 : 0);
	}
}

ll CountPPC()
{
	ll Cnt = 0;
	for (int i = 1; i < N; ++i)
	{
		if (PPC[i] == 'C')
		{
			continue;
		}

		Cnt += (ll)NumP[i] * NumC[i];
	}

	return Cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Init();
	MakePPC();
	cout << CountPPC();
}