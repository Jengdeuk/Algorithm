#include <string>
#include <vector>

using namespace std;

const int maxN = 16;

int n, m, k;
vector<vector<int>> c, h;

int minCost = 1234567890;
int card[maxN];

void DFS(int idx, int curCost)
{
    if (idx == n)
    {
        minCost = min(minCost, curCost);
        return;
    }

    int newCost = curCost + c[idx][card[idx] >= m ? m - 1 : card[idx]];

    DFS(idx + 1, newCost);

    if (idx == n - 1)
    {
        return;
    }

    for (int i = 0; i < k; ++i)
    {
        ++card[h[idx][1 + i] - 1];
    }

    DFS(idx + 1, newCost + h[idx][0]);

    for (int i = 0; i < k; ++i)
    {
        --card[h[idx][1 + i] - 1];
    }
}

int solution(vector<vector<int>> cost, vector<vector<int>> hint)
{
    n = cost.size();
    m = cost[0].size();
    k = hint[0].size() - 1;

    c = cost;
    h = hint;

    DFS(0, 0);

    return minCost;
}