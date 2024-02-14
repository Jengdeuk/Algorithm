#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Times;
int Sums[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	Times.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Time;
		cin >> Time;
		Times.emplace_back(Time);
	}

	sort(Times.begin(), Times.end());

	Sums[0] = Times[0];
	for (int i = 1; i < N; ++i)
	{
		Sums[i] = Sums[i - 1] + Times[i];
	}

	int Sum = 0;
	for (int i = 0; i < N; ++i)
	{
		Sum += Sums[i];
	}

	cout << Sum;
}