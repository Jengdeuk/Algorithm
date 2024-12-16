#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

unordered_map<string, int> UM;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string S;
		cin >> S;
		++UM[S];
	}

	for (pair<string, int> p : UM)
	{
		string PW = p.first;
		reverse(PW.begin(), PW.end());
		if (UM.count(PW))
		{
			cout << PW.size() << ' ' << PW[PW.size() / 2];
			break;
		}
	}
}