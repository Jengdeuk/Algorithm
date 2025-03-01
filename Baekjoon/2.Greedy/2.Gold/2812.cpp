#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, k;
	cin >> n >> k;

	string s;
	cin >> s;

	stack<int> st;
	for (int i = 0; i < n; ++i)
	{
		int num = s[i] - '0';
		while (k > 0 && st.empty() == false && num > st.top())
		{
			st.pop();
			--k;
		}

		st.emplace(num);
	}

	while (k > 0)
	{
		st.pop();
		--k;
	}

	stack<int> strv;
	while (st.empty() == false)
	{
		strv.emplace(st.top());
		st.pop();
	}

	while (strv.empty() == false)
	{
		cout << strv.top();
		strv.pop();
	}
}