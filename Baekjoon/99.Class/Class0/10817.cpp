#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	vector<int> Seq(3, 0);
	for (int i = 0; i < 3; ++i)
	{
		cin >> Seq[i];
	}
	sort(Seq.begin(), Seq.end());
	cout << Seq[1];
}