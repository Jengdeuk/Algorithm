#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string L, R;
	cin >> L >> R;

	int Count = 0;
	if (L.size() == R.size())
	{
		for (int i = 0; i < L.size(); ++i)
		{
			if (L[i] == '8' && L[i] == R[i])
			{
				++Count;
			}
			else if (L[i] != R[i])
			{
				break;
			}
		}
	}

	cout << Count;
}