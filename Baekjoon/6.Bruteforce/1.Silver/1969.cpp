#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef pair<int, string> p;

int N, M;
string S[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	string Answer;
	int Cnt = 0;
	for (int j = 0; j < M; ++j)
	{
		int ACGT[4] = {};
		for (int i = 0; i < N; ++i)
		{
			switch (S[i][j])
			{
			case 'A':
				ACGT[0]++;
				break;
			case 'C':
				ACGT[1]++;
				break;
			case 'G':
				ACGT[2]++;
				break;
			case 'T':
				ACGT[3]++;
				break;
			}
		}

		switch (max_element(ACGT, ACGT + 4) - ACGT)
		{
		case 0:
			Answer.push_back('A');
			Cnt += ACGT[1] + ACGT[2] + ACGT[3];
			break;
		case 1:
			Answer.push_back('C');
			Cnt += ACGT[2] + ACGT[3] + ACGT[0];
			break;
		case 2:
			Answer.push_back('G');
			Cnt += ACGT[3] + ACGT[0] + ACGT[1];
			break;
		case 3:
			Answer.push_back('T');
			Cnt += ACGT[0] + ACGT[1] + ACGT[2];
			break;
		}
	}

	cout << Answer << '\n';
	cout << Cnt;
}