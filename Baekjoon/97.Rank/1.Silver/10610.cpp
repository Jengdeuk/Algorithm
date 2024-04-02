#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Seq;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string N;
	cin >> N;
	Seq.reserve(N.size());

	int Sum = 0;
	bool bZeroExist = false;
	for (int i = 0; i < N.size(); ++i)
	{
		if (N[i] == '0')
		{
			bZeroExist = true;
		}

		int Num = N[i] - '0';
		Sum += Num;
		Seq.emplace_back(Num);
	}

	if (!bZeroExist || Sum % 3 != 0)
	{
		cout << -1;
		return 0;
	}

	sort(Seq.begin(), Seq.end(), greater<>());

	for (const int& Num : Seq)
	{
		cout << Num;
	}
}