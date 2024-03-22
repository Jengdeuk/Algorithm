#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> LIS;
int Sequence[1000000];
int Index[1000000];
stack<int> Result;

int BinarySearch(int Number)
{
	int L = 0;
	int R = LIS.size() - 1;
	while (L < R)
	{
		int M = (L + R) / 2;
		if (LIS[M] < Number)
		{
			L = M + 1;
		}
		else
		{
			R = M;
		}
	}

	return L;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int Number;
		cin >> Number;
		Sequence[i] = Number;
		if (i == 0 || Number > LIS.back())
		{
			LIS.emplace_back(Number);
			Index[i] = LIS.size() - 1;
		}
		else
		{
			int Idx = BinarySearch(Number);
			LIS[Idx] = Number;
			Index[i] = Idx;
		}
	}

	int Idx = LIS.size() - 1;
	for (int i = N - 1; i >= 0; --i)
	{
		if (Index[i] == Idx)
		{
			Result.emplace(Sequence[i]);
			--Idx;
		}
	}

	cout << LIS.size() << '\n';
	while (!Result.empty())
	{
		cout << Result.top() << ' ';
		Result.pop();
	}
}