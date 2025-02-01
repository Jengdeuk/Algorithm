#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isGoodWord(string word)
{
	stack<char> st;
	for (const char ch : word)
	{
		if (st.empty() || st.top() != ch)
			st.emplace(ch);
		else
			st.pop();
	}

	return (st.empty());
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		string w;
		cin >> w;
		cnt += isGoodWord(w);
	}

	cout << cnt;
}