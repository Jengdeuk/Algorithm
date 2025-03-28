#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;

struct ball
{
	int number;
	int color;
	int size;
	ll eat;

	bool operator<(const ball& r) const
	{
		return size == r.size ? (color == r.color ? number < r.number : color < r.color) : size < r.size;
	}
};

bool compare(const ball& l, const ball& r)
{
	return l.number < r.number;
}

int n;
ll sum, cs[200001];
ball b[200000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		b[i].number = i;
		cin >> b[i].color >> b[i].size;
	}

	sort(b, b + n);

	int ps = 0;
	queue<p> q;
	for (int i = 0; i < n; ++i)
	{
		if (ps != b[i].size)
		{
			while (q.empty() == false)
			{
				sum += q.front().second;
				cs[q.front().first] += q.front().second;
				q.pop();
			}

			ps = b[i].size;
		}

		b[i].eat = sum - cs[b[i].color];

		if (ps == b[i].size)
		{
			q.emplace(b[i].color, b[i].size);
		}
		else
		{
			sum += b[i].size;
			cs[b[i].color] += b[i].size;
		}
	}

	sort(b, b + n, compare);

	for (int i = 0; i < n; ++i)
		cout << b[i].eat << '\n';
}