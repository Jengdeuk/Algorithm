#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int N, K, S[10], O[10];
bool V[10];

unordered_set<string> Set;

void BT(int Idx)
{
	if (Idx == K)
	{
		string Str;
		for (int i = 0; i < K; ++i)
		{
			Str.append(to_string(S[O[i]]));
		}
		Set.insert(Str);
		return;
	}

	for (int i = 0; i < N; ++i)
	{
		if (V[i])
		{
			continue;
		}

		V[i] = true;
		O[Idx] = i;
		BT(Idx + 1);
		V[i] = false;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	BT(0);

	cout << Set.size();
}