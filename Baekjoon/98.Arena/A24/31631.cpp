#include <iostream>
#include <vector>
using namespace std;

vector<int> H;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	H.reserve(N);

	H.emplace_back(1);
	H.emplace_back(2);
	for (int i = 2; i < N; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			++H[j];
		}

		int Index;
		switch (i % 4)
		{
		case 0:
		case 2:
			Index = i / 2;
			break;

		case 1:
			Index = (i - 1) / 2;
			break;

		case 3:
			Index = (i - 1) / 2 + 1;
			break;
		}

		H.insert(H.begin() + Index, 1);
	}

	for (const int& Num : H)
	{
		cout << Num << ' ';
	}
}