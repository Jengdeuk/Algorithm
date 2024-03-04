#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	vector<int> Seq(5);
	
	int Sum = 0;
	for (int i = 0; i < 5; ++i)
	{
		int Num;
		cin >> Num;
		Seq[i] = Num;
		Sum += Num;
	}

	sort(Seq.begin(), Seq.end());

	cout << Sum / 5 << '\n';
	cout << Seq[2];
}