#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, int> M;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		++M[S];
	}

	string Answer;
	int Max = 0;
	for (const pair<string, int>& p : M)
	{
		if (p.second > Max || (p.second == Max && p.first < Answer))
		{
			Answer = p.first;
			Max = p.second;
		}
	}

	cout << Answer;
}