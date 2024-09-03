#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

typedef pair<int, int> p;

const int DX[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
const int DY[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };

unordered_map<string, int> Convert;
p R, K;

bool IsInvalid(int NR, int NC)
{
	return !(NR >= 0 && NR < 8 && NC >= 0 && NC < 8);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Convert["R"] = 0;
	Convert["L"] = 1;
	Convert["B"] = 2;
	Convert["T"] = 3;
	Convert["RT"] = 4;
	Convert["LT"] = 5;
	Convert["RB"] = 6;
	Convert["LB"] = 7;

	string King, Rock;
	cin >> King >> Rock;
	K = p(King[1] - '0' - 1, King[0] - 'A');
	R = p(Rock[1] - '0' - 1, Rock[0] - 'A');

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string Direction;
		cin >> Direction;

		int D = Convert[Direction];
		int NR = K.first + DY[D];
		int NC = K.second + DX[D];
		if (IsInvalid(NR, NC))
		{
			continue;
		}

		if (R.first == NR && R.second == NC)
		{
			int NRR = R.first + DY[D];
			int NRC = R.second + DX[D];
			if (IsInvalid(NRR, NRC))
			{
				continue;
			}

			R = p(NRR, NRC);
		}

		K = p(NR, NC);
	}

	King.clear();
	King.push_back('A' + K.second);
	King.push_back('0' + K.first + 1);

	Rock.clear();
	Rock.push_back('A' + R.second);
	Rock.push_back('0' + R.first + 1);

	cout << King << '\n';
	cout << Rock;
}