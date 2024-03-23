#include <iostream>
#include <deque>
using namespace std;

deque<int> DQ;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		DQ.push_back(i);
	}

	int Cnt = 0;
	for (int i = 0; i < M; ++i)
	{
		int Num;
		cin >> Num;
		if (DQ.front() == Num)
		{
			DQ.pop_front();
			continue;
		}

		deque<int> Temp(DQ);
		
		int F = 0;
		while (Temp.front() != Num)
		{
			Temp.pop_front();
			++F;
		}

		int B = 1;
		while (Temp.back() != Num)
		{
			Temp.pop_back();
			++B;
		}

		if (F <= B)
		{
			while (DQ.front() != Num)
			{
				DQ.push_back(DQ.front());
				DQ.pop_front();
				++Cnt;
			}
		}
		else
		{
			while (DQ.back() != Num)
			{
				DQ.push_front(DQ.back());
				DQ.pop_back();
				++Cnt;
			}
			DQ.push_front(DQ.back());
			DQ.pop_back();
			++Cnt;
		}

		DQ.pop_front();
	}

	cout << Cnt;
}