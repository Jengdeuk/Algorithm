#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[1001];
int B[1001];

vector<int> ASum;
vector<int> BSum;

void Init()
{
	int N, M;

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}

	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		cin >> B[i];
	}

	ASum.reserve(N * N);
	for (int i = 0; i < N; ++i)
	{
		int Sum = A[i];
		ASum.emplace_back(Sum);
		for (int j = i + 1; j < N; ++j)
		{
			Sum += A[j];
			ASum.emplace_back(Sum);
		}
	}

	BSum.reserve(M * M);
	for (int i = 0; i < M; ++i)
	{
		int Sum = B[i];
		BSum.emplace_back(Sum);
		for (int j = i + 1; j < M; ++j)
		{
			Sum += B[j];
			BSum.emplace_back(Sum);
		}
	}

	sort(BSum.begin(), BSum.end());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;

	Init();

	long long Cnt = 0;
	for (const int& AS : ASum)
	{
		int FindNum = T - AS;
		vector<int>::iterator Up = upper_bound(BSum.begin(), BSum.end(), FindNum);
		vector<int>::iterator Low = lower_bound(BSum.begin(), BSum.end(), FindNum);
		Cnt += (Up - Low);
	}

	cout << Cnt;
}