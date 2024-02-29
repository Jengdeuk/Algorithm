#include <iostream>
#include <vector>
using namespace std;

vector<int> Sum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	Sum.reserve(N);
	for (int i = 0; i < N; ++i)
	{
		int Number;
		cin >> Number;

		if (i == 0)
		{
			Sum.emplace_back(Number);
		}
		else
		{
			Sum.emplace_back(Sum[i - 1] + Number);
		}
	}

	for (int i = 0; i < M; ++i)
	{
		int A, B;
		cin >> A >> B;

		int Src = A - 2;
		int Dst = B - 1;

		if (Src < 0)
		{
			cout << Sum[Dst] << '\n';
		}
		else
		{
			cout << Sum[Dst] - Sum[Src] << '\n';
		}
	}
}