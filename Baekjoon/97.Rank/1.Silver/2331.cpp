#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> Vst;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int A, P;
	cin >> A >> P;
	while (find(Vst.begin(), Vst.end(), A) == Vst.end())
	{
		Vst.emplace_back(A);

		int Sum = 0;
		while (A > 0)
		{
			Sum += pow(A % 10, P);
			A /= 10;
		}

		A = Sum;
	}

	cout << find(Vst.begin(), Vst.end(), A) - Vst.begin();
}