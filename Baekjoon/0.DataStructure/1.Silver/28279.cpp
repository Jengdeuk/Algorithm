#include <iostream>
#include <deque>
using namespace std;

deque<int> q;

void command()
{
	int input;
	cin >> input;
	switch (input)
	{
	case 1:
	{
		int x;
		cin >> x;
		q.emplace_front(x);
	}
		break;
	case 2:
	{
		int x;
		cin >> x;
		q.emplace_back(x);
	}
		break;
	case 3:
	{
		if (q.empty() == false)
		{
			cout << q.front() << '\n';
			q.pop_front();
		}
		else
		{
			cout << -1 << '\n';
		}
	}
		break;
	case 4:
	{
		if (q.empty() == false)
		{
			cout << q.back() << '\n';
			q.pop_back();
		}
		else
		{
			cout << -1 << '\n';
		}
	}
		break;
	case 5:
	{
		cout << q.size() << '\n';
	}
		break;
	case 6:
	{
		cout << q.empty() << '\n';
	}
		break;
	case 7:
	{
		if (q.empty() == false)
		{
			cout << q.front() << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}
		break;
	case 8:
	{
		if (q.empty() == false)
		{
			cout << q.back() << '\n';
		}
		else
		{
			cout << -1 << '\n';
		}
	}
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n;
	cin >> n;
	while (n--) command();
}