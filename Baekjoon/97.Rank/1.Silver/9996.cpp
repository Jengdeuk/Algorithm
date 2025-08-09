#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	string P;
	cin >> P;

	int Idx = P.find('*');
	string L = P.substr(0, Idx), R = P.substr(Idx + 1);
	while (N--)
	{
		string S;
		cin >> S;
		if (S.size() < L.size())
		{
			cout << "NE\n";
			continue;
		}

		bool bCorrect = true;
		for (int i = 0; i < L.size(); ++i)
		{
			if (S[i] != L[i])
			{
				bCorrect = false;
				break;
			}
		}

		if (bCorrect == false || S.size() - L.size() < R.size())
		{
			cout << "NE\n";
			continue;
		}

		if (R.empty() == false)
		{
			int j = R.size() - 1;
			for (int i = S.size() - 1; i >= S.size() - R.size(); --i)
			{
				if (S[i] != R[j--])
				{
					bCorrect = false;
					break;
				}
			}
		}

		if (bCorrect)
		{
			cout << "DA\n";
		}
		else
		{
			cout << "NE\n";
		}
	}
}