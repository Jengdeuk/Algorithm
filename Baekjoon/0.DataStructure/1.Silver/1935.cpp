#include <iostream>
#include <string>
#include <stack>
using namespace std;

int a[26];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;

	string s;
	cin >> s;

	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	stack<double> st;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			st.emplace(a[s[i] - 'A']);
			continue;
		}

		double n1 = st.top();
		st.pop();

		double n2 = st.top();
		st.pop();

		double rv = 0;
		switch (s[i])
		{
		case '+':
			rv = n2 + n1;
			break;
		case '-':
			rv = n2 - n1;
			break;
		case '*':
			rv = n2 * n1;
			break;
		case '/':
			rv = n2 / n1;
			break;
		}
		st.emplace(rv);
	}

	cout.precision(2);
	cout << fixed << st.top();
}