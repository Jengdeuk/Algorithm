#include <iostream>
#include <stack>
using namespace std;

typedef pair<int, int> p;

int n, a[1000000], f[1000001], s[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		a[i] = num;
		++f[num];
	}

	stack<p> st;
	for (int i = 0; i < n; ++i)
	{
		while (st.empty() == false && st.top().first < f[a[i]])
		{
			s[st.top().second] = a[i];
			st.pop();
		}
		st.emplace(f[a[i]], i);
	}

	while (st.empty() == false)
	{
		s[st.top().second] = -1;
		st.pop();
	}

	for (int i = 0; i < n; ++i)
		cout << s[i] << ' ';
}