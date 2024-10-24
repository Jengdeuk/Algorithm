#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;
	
	int Idx = 0;
	int KDA[3] = {};
	string Sub;
	for (int i = 0; i < S.size(); ++i)
	{
		if (S[i] != '/')
		{
			Sub.push_back(S[i]);
		}
		else
		{
			KDA[Idx++] = stoi(Sub);
			Sub.clear();
		}
	}

	KDA[Idx++] = stoi(Sub);
	Sub.clear();

	if (KDA[0] + KDA[2] < KDA[1] || KDA[1] == 0)
	{
		cout << "hasu";
	}
	else
	{
		cout << "gosu";
	}
}