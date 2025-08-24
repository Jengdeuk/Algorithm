#include <iostream>
using namespace std;

int N, S[100000], LS[100002], RS[100002];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	int Answer = -1000;

	for (int i = 1; i <= N; ++i)
	{
		Answer = max(Answer, LS[i] = max(LS[i - 1] + S[i - 1], S[i - 1]));
	}

	for (int i = N; i >= 1; --i)
	{
		Answer = max(Answer, RS[i] = max(RS[i + 1] + S[i - 1], S[i - 1]));
	}

	for (int i = 2; i <= N - 1; ++i)
	{
		Answer = max(Answer, LS[i - 1] + RS[i + 1]);
	}

	cout << Answer;
}