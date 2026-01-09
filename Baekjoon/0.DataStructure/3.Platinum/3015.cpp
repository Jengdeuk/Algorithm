#include <iostream>
#include <stack>
#include <set>
using namespace std;

typedef pair<int, int> p;

stack<p> st;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	
	long long cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int h;
		cin >> h;
		if (st.empty())
		{
			st.emplace(h, 1);
			continue;
		}

		int same = 1;
		while (st.empty() == false)
		{
			if (st.top().first < h)
			{
				cnt += st.top().second;
				st.pop();
			}
			else if (st.top().first > h)
			{
				cnt += 1;
				break;
			}
			else
			{
				cnt += st.top().second;
				same = st.top().second + 1;
				st.pop();
			}
		}

		st.emplace(h, same);
	}

	cout << cnt;
}