#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A;
vector<int> B;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	A.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;
		A.emplace_back(Num);
	}

	B.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Num;
		cin >> Num;
		B.emplace_back(Num);
	}

	sort(A.begin(), A.end());
	sort(B.begin(), B.end(), greater<>());

	int Sum = 0;
	for (int i = 0; i < N; ++i)
	{
		Sum += A[i] * B[i];
	}

	cout << Sum;
}