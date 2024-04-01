#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

unordered_set<string> Name;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string First, Second;
		cin >> First >> Second;

		if (Second.compare("enter") == 0)
		{
			Name.emplace(First);
		}
		else if(Name.find(First) != Name.end())
		{
			Name.erase(Name.find(First));
		}
	}

	vector<string> Name2(Name.begin(), Name.end());
	sort(Name2.begin(), Name2.end(), greater<>());
	
	for (const string& N : Name2)
	{
		cout << N << '\n';
	}
}