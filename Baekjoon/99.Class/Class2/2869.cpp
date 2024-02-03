#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int A, B, V;
	cin >> A >> B >> V;

	int Days = 1;
	int RemainHeight = V - A;
	int Performance = A - B;

	if (RemainHeight <= 0)
	{
	}
	else if (RemainHeight % Performance == 0)
	{
		Days += RemainHeight / Performance;
	}
	else 
	{
		Days += RemainHeight / Performance + 1;
	}

	cout << Days;
}