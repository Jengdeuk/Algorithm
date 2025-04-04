#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> ii;

priority_queue<ii> q;

int pay[10000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

    int n, md = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int d, p;
        cin >> p >> d;
        q.emplace(p, d);
        md = max(md, d);
    }

    while (q.empty() == false)
    {
        int p = q.top().first;
        int d = q.top().second;
        q.pop();

        for (int i = d - 1; i >= 0; --i)
        {
            if (pay[i] != 0)
                continue;

            pay[i] = p;
            break;
        }
    }

    int sum = 0;
    for (int i = 0; i < md; ++i)
        sum += pay[i];

    cout << sum;
}