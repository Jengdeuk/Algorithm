#include <iostream>
#include <vector>
using namespace std;

void Test()
{
	int N;
	cin >> N;

	float Sum = 0;
	vector<int> Students(N);
	for (int i = 0; i < N; ++i)
	{
		int Score;
		cin >> Score;
		Sum += Score;
		Students[i] = Score;
	}

	float Average = Sum / N;

	int Cnt = 0;
	for (const int& Score : Students)
	{
		if (float(Score) > Average)
		{
			++Cnt;
		}
	}
	
	cout << fixed;
	cout.precision(3);
	cout << float(Cnt) / N * 100.f << "%\n";
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int C;
	cin >> C;

	for (int i = 0; i < C; ++i)
	{
		Test();
	}
}