#include <iostream>
using namespace std;

int Num[500001], Sum[500001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int Q;
	cin >> Q;
	
	int S = 0, E = 0;
	for (int i = 0; i < Q; ++i)
	{
		int A;
		cin >> A;
		if (A == 1)
		{
			++E;
			cin >> Num[E];
			Sum[E] = Sum[E - 1] + Num[E];
		}
		else
		{
			int SumL = Sum[(S + E) / 2] - Sum[S];
			int SumR = Sum[E] - Sum[(S + E) / 2];
			if (SumL > SumR)
			{
				E = (S + E) / 2;
				cout << SumR << '\n';
			}
			else
			{
				S = (S + E) / 2;
				cout << SumL << '\n';
			}
		}
	}

	for (int i = S + 1; i <= E; ++i)
	{
		cout << Num[i] << ' ';
	}
}