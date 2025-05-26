#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string a, b;
	cin >> a >> b;

	transform(a.begin(), a.end(), a.begin(), ::tolower);
	transform(b.begin(), b.end(), b.begin(), ::tolower);

	bool isFinished = false;
	for (int i = 0; i < a.size(); ++i)
	{
		if (a[i] < b[i])
		{
			isFinished = true;
			cout << -1;
			break;
		}
		else if (a[i] > b[i])
		{
			isFinished = true;
			cout << 1;
			break;
		}
	}

	if (isFinished == false)
	{
		cout << 0;
	}
}