#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int N, M, K;
string F[50];

bool Comp(const pair<string, int>& L, const pair<string, int>& R)
{
	return (L.second == R.second ? L.first < R.first : L.second < R.second);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> F[i];
	}

	bool bCompleted = false;
	for (int i = 1; i <= M; ++i)
	{
		unordered_map<string, int> Map;

		for (int j = 0; j < N; ++j)
		{
			string S = F[j].substr(0, i);
			string Key;
			for (int k = 0; k < i; ++k)
			{
				Key.push_back(S[k]);
			}

			++Map[Key];
		}

		string MinKey = (*min_element(Map.begin(), Map.end(), Comp)).first;
		if (Map[MinKey] <= K)
		{
			bCompleted = true;
			cout << i << '\n';
			for (int i = 0; i < MinKey.size(); ++i)
			{
				switch (MinKey[i])
				{
				case 'S':
					cout << 'P';
					break;

				case 'R':
					cout << 'S';
					break;

				case 'P':
					cout << 'R';
					break;
				}
			}
			break;
		}
	}

	if (!bCompleted)
	{
		cout << -1;
	}
}