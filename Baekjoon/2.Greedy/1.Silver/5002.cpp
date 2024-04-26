#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int X;
	cin >> X;

	string Line;
	cin >> Line;

	if (Line.size() == 1)
	{
		cout << 1;
		return 0;
	}

	int Men = 0, Women = 0;
	int F = 0;
	for (int i = 1; i < Line.size(); ++i)
	{
		if (Line[F] != Line[i])
		{
			if (Line[F] == 'M')
			{
				if (Men <= Women)
				{
					++Men;
					F = i;
				}
				else
				{
					++Women;
				}
			}
			else
			{
				if (Women <= Men)
				{
					++Women;
					F = i;
				}
				else
				{
					++Men;
				}
			}
		}
		else if (Line[F] == Line[i])
		{
			if (Line[F] == 'M')
			{
				++Men;
				if (abs(Men - Women) > X)
				{
					--Men;
					break;
				}
			}
			else
			{
				++Women;
				if (abs(Men - Women) > X)
				{
					--Women;
					break;
				}
			}

			F = i;
		}
	}

	if (abs(Men - Women) <= X)
	{
		if (Line[F] == 'M')
		{
			Men += (abs((Men + 1) - Women) > X ? 0 : 1);
		}
		else
		{
			Women += (abs(Men - (Women + 1)) > X ? 0 : 1);
		}
	}

	cout << Men + Women;
}