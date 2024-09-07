#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;

typedef pair<int, string> p;

int N;
int LOVE[4];
p Name[50];

bool Compare(const p& L, const p& R)
{
	return (L.first == R.first ? L.second < R.second : L.first > R.first);
}

int ConvertCharToIndex(char Ch)
{
	switch (Ch)
	{
	case 'L':
		return 0;
	case 'O':
		return 1;
	case 'V':
		return 2;
	case 'E':
		return 3;
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string A;
	cin >> A >> N;
	
	for (int i = 0; i < A.size(); ++i)
	{
		int Index = ConvertCharToIndex(A[i]);
		if (Index > -1)
		{
			++LOVE[Index];
		}
	}
	
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;

		int Count[4] = {};
		memcpy(Count, LOVE, sizeof(Count));

		for (int j = 0; j < S.size(); ++j)
		{
			int Index = ConvertCharToIndex(S[j]);
			if (Index > -1)
			{
				++Count[Index];
			}
		}

		int Sum = 1;
		for (int j = 0; j < 4; ++j)
		{
			for (int k = j + 1; k < 4; ++k)
			{
				Sum *= Count[j] + Count[k];
				Sum %= 100;
			}
		}

		Name[i].first = Sum;
		Name[i].second = S;
	}

	sort(Name, Name + N, Compare);

	cout << Name[0].second;
}