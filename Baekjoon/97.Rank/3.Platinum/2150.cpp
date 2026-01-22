#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

int v, e;

vector<int> fn[10001];
vector<int> bn[10001];
stack<int> st;
vector<vector<int>> answer;

bool vst[10001];
vector<int> curGroup;

void DFS1(int cur)
{
	vst[cur] = true;
	for (const int nxt : fn[cur])
	{
		if (vst[nxt])
		{
			continue;
		}

		DFS1(nxt);
	}

	st.push(cur);
}

void DFS2(int cur)
{
	vst[cur] = true;
	for (const int nxt : bn[cur])
	{
		if (vst[nxt])
		{
			continue;
		}

		DFS2(nxt);
	}

	curGroup.emplace_back(cur);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);
	
	cin >> v >> e;
	for (int i = 0; i < e; ++i)
	{
		int src, dst;
		cin >> src >> dst;

		fn[src].emplace_back(dst);
		bn[dst].emplace_back(src);
	}

	for (int i = 1; i <= v; ++i)
	{
		sort(fn[i].begin(), fn[i].end());
		sort(bn[i].begin(), bn[i].end());
	}

	for (int i = 1; i <= v; ++i)
	{
		if (vst[i])
		{
			continue;
		}

		DFS1(i);
	}

	memset(vst, false, sizeof(vst));

	while (st.empty() == false)
	{
		int cur = st.top();
		st.pop();

		if (vst[cur])
		{
			continue;
		}

		DFS2(cur);
		
		sort(curGroup.begin(), curGroup.end());
		answer.emplace_back(curGroup);
		vector<int>().swap(curGroup);
	}

	sort(answer.begin(), answer.end());

	cout << answer.size() << '\n';
	for (const vector<int>& curGroup : answer)
	{
		for (const int node : curGroup)
		{
			cout << node << ' ';
		}

		cout << "-1\n";
	}
}