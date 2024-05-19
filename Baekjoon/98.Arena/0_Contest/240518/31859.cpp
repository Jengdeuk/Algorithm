#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool Sel[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	string S;
	cin >> N >> S;

	int Cnt = 0;
	string Temp;
	for (int i = 0; i < S.size(); ++i)
	{
		char ch = S[i];
		if (!Sel[ch - 'a'])
		{
			Sel[ch - 'a'] = true;
			Temp.push_back(ch);
		}
		else
		{
			++Cnt;
		}
	}

	Cnt += 4;
	Temp.append(to_string(Cnt));
	Cnt = N + 1906;
	S = to_string(Cnt);
	S.append(Temp);
	reverse(S.begin(), S.end());
	cout << "smupc_" << S;
}