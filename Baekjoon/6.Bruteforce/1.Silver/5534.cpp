#include <iostream>
#include <string>
using namespace std;

string Origin, New;

bool Check(int S)
{
	if (New.size() - S < Origin.size())
	{
		return false;
	}

	int Gap = 1;
	while (S + Gap < New.size())
	{
		int O = 0;
		for (int N = S; N < New.size(); N += Gap)
		{
			if (New[N] != Origin[O])
			{
				break;
			}

			++O;
			if (O == Origin.size())
			{
				return true;
			}
		}

		++Gap;
	}

	return false;
}

bool Solve()
{
	if (New.size() < Origin.size())
	{
		return false;
	}
	else if (New.size() == Origin.size())
	{
		if (New.compare(Origin) == 0) return true;
		else return false;
	}

	bool bFind = false;
	for (int i = 0; i < New.size(); ++i)
	{
		if (New[i] == Origin[0] && Check(i))
		{
			bFind = true;
			break;
		}
	}

	return bFind;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N >> Origin;

	int Cnt = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> New;
		Cnt += (Solve()) ? 1 : 0;
	}

	cout << Cnt;
}