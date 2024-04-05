#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> point;

ll X1, Y1, X2, Y2, X3, Y3, X4, Y4;
point P1, P2, P3, P4;

ll CCW(point A, point B, point C)
{
	ll Result = (B.first - A.first) * (C.second - A.second);
	Result -= (C.first - A.first) * (B.second - A.second);
	
	if (Result > 0)
	{
		return 1;
	}
	else if (Result < 0)
	{
		return -1;
	}

	return 0;
}

bool Intersect()
{
	ll C1 = CCW(P1, P2, P3);
	ll C2 = CCW(P1, P2, P4);
	ll C3 = CCW(P3, P4, P1);
	ll C4 = CCW(P3, P4, P2);

	ll Con1 = C1 * C2;
	ll Con2 = C3 * C4;

	if (Con1 < 0 && Con2 < 0)
	{
		return true;
	}
	else if ((Con1 == 0 && Con2 < 0)
			|| (Con1 < 0 && Con2 == 0)
			|| ((Con1 == 0 && Con2 == 0) && (C1 != 0 || C2 != 0) && (C3 != 0 || C4 != 0)))
	{
		return true;
	}
	else if (C1 == 0 && C2 == 0 && C3 == 0 && C4 == 0)
	{
		if (X1 == X2)
		{
			if (Y1 < Y2 && Y3 < Y4
				&& Y3 <= Y2 && Y1 <= Y4)
			{
				return true;
			}
			else if (Y1 < Y2 && Y3 > Y4
				&& Y4 <= Y2 && Y1 <= Y3)
			{
				return true;
			}
			else if (Y1 > Y2 && Y3 < Y4
				&& Y3 <= Y1 && Y2 <= Y4)
			{
				return true;
			}
			else if (Y1 > Y2 && Y3 > Y4
				&& Y4 <= Y1 && Y2 <= Y3)
			{
				return true;
			}
		}
		else if (X1 < X2 && X3 < X4
				&& X3 <= X2 && X1 <= X4)
		{
			return true;
		}
		else if (X1 < X2 && X3 > X4
				&& X4 <= X2 && X1 <= X3)
		{
			return true;
		}
		else if (X1 > X2 && X3 < X4
				&& X3 <= X1 && X2 <= X4)
		{
			return true;
		}
		else if (X1 > X2 && X3 > X4
				&& X4 <= X1 && X2 <= X3)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> X1 >> Y1 >> X2 >> Y2;
	cin >> X3 >> Y3 >> X4 >> Y4;

	P1.first = X1;
	P1.second = Y1;
	P2.first = X2;
	P2.second = Y2;

	P3.first = X3;
	P3.second = Y3;
	P4.first = X4;
	P4.second = Y4;

	cout << Intersect();
}