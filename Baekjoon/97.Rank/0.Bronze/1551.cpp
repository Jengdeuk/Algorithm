#include <iostream>
#include <string>
using namespace std;

int N, K;
int S[20];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> K;
	
	string Str;
	cin >> Str;

	int Idx = 0;
	string Cur;
	for (int i = 0; i < Str.size(); ++i)
	{
		if (Str[i] == ',')
		{
			S[Idx++] = stoi(Cur);
			Cur.clear();
		}
		else
		{
			Cur.push_back(Str[i]);
		}
	}
	S[Idx] = stoi(Cur);

	for (int i = 0; i < K; ++i)
	{
		for (int j = 0; j < N - 1; ++j)
		{
			S[j] = S[j + 1] - S[j];
		}
		--N;
	}

	for (int i = 0; i < N - 1; ++i)
	{
		cout << S[i] << ',';
	}
	cout << S[N - 1];
}