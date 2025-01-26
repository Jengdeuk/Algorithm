#include <iostream>
#include <stack>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	stack<int> st;

	int n;
	cin >> n;

	int index = 1;
	for (int i = 0; i < n; ++i)
	{
		int front;
		cin >> front;
		if (front == index)
		{
			++index;
		}
		else if (front != index && st.empty())
		{
			st.emplace(front);
		}
		else
		{
			while (st.empty() == false && st.top() == index)
			{
				++index;
				st.pop();
			}

			st.emplace(front);
		}
	}

	while (st.empty() == false)
	{
		if (st.top() == index)
		{
			++index;
		}

		st.pop();
	}

	if (index == n + 1)
	{
		cout << "Nice";
	}
	else
	{
		cout << "Sad";
	}
}