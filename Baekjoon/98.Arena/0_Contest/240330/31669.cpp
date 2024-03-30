#include <iostream>
#include <string>
using namespace std;

char Schedule[100][100];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string Str;
		cin >> Str;

		for (int j = 0; j < M; ++j)
		{
			Schedule[i][j] = Str[j];
		}
	}

	int Index = -1;
	for (int j = 0; j < M; ++j)
	{
		bool bEscape = true;
		for (int i = 0; i < N; ++i)
		{
			if (Schedule[i][j] == 'O')
			{
				bEscape = false;
			}
		}

		if (bEscape)
		{
			Index = j + 1;
			break;
		}
	}

	if (Index >= 1)
	{
		cout << Index;
	}
	else
	{
		cout << "ESCAPE FAILED";
	}
}