#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;

unordered_set<string> DontHears;
unordered_set<string> DontLooks;
vector<string> DontHearLooks;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string DontHear;
		cin >> DontHear;
		DontHears.emplace(DontHear);
	}

	for (int i = 0; i < M; ++i)
	{
		string DontLook;
		cin >> DontLook;
		DontLooks.emplace(DontLook);
	}

	DontHearLooks.reserve(500001);
	for (const string& DontHear : DontHears)
	{
		if (DontLooks.find(DontHear) != DontLooks.end())
		{
			DontHearLooks.emplace_back(DontHear);
		}
	}

	sort(DontHearLooks.begin(), DontHearLooks.end());

	cout << DontHearLooks.size() << '\n';
	for (const string& DontHearLook : DontHearLooks)
	{
		cout << DontHearLook << '\n';
	}
}