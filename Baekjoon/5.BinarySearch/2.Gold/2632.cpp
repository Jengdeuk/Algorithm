#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int A[1000], B[1000];
vector<int> AS, BS;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int P, N, M;
	cin >> P >> N >> M;

	AS.reserve(N * N);
	BS.reserve(M * M);

	int Sum = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		Sum += A[i];
	}
	
	AS.emplace_back(Sum);
	for (int i = 0; i < N; ++i)
	{
		Sum = 0;
		for (int j = i; j < i + N - 1; ++j)
		{
			Sum += A[j % N];
			AS.emplace_back(Sum);
		}
	}

	Sum = 0;
	for (int i = 0; i < M; ++i)
	{
		cin >> B[i];
		Sum += B[i];
	}

	BS.emplace_back(Sum);
	for (int i = 0; i < M; ++i)
	{
		Sum = 0;
		for (int j = i; j < i + M - 1; ++j)
		{
			Sum += B[j % M];
			BS.emplace_back(Sum);
		}
	}

	sort(AS.begin(), AS.end());
	sort(BS.begin(), BS.end());

	int Cnt = 0;

	int UI = upper_bound(AS.begin(), AS.end(), P) - AS.begin();
	int LI = lower_bound(AS.begin(), AS.end(), P) - AS.begin();
	Cnt += UI - LI;

	UI = upper_bound(BS.begin(), BS.end(), P) - BS.begin();
	LI = lower_bound(BS.begin(), BS.end(), P) - BS.begin();
	Cnt += UI - LI;

	for (const int S1 : AS)
	{
		int Piece = P - S1;
		if (Piece <= 0)
		{
			break;
		}

		UI = upper_bound(BS.begin(), BS.end(), Piece) - BS.begin();
		LI = lower_bound(BS.begin(), BS.end(), Piece) - BS.begin();
		Cnt += UI - LI;
	}

	cout << Cnt;
}