#include <iostream>
#include <unordered_map>
using namespace std;

typedef pair<int, int> point;
typedef pair<point, point> line;

int N;
line Lines[3000];
int Root[3000];
unordered_map<int, int> HashMap;

int Find(int Node)
{
	if (Node == Root[Node])
	{
		return Node;
	}

	return Root[Node] = Find(Root[Node]);
}

void Union(int NodeA, int NodeB)
{
	int A = Find(NodeA);
	int B = Find(NodeB);
	int Min = min(A, B);
	Root[A] = Min;
	Root[B] = Min;
}

int CCW(point A, point B, point C)
{
	int Result = (B.first - A.first) * (C.second - A.second);
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

bool Intersect(point P1, point P2, point P3, point P4)
{
	int X1 = P1.first, X2 = P2.first, X3 = P3.first, X4 = P4.first;
	int Y1 = P1.second, Y2 = P2.second, Y3 = P3.second, Y4 = P4.second;

	int C1 = CCW(P1, P2, P3);
	int C2 = CCW(P1, P2, P4);
	int C3 = CCW(P3, P4, P1);
	int C4 = CCW(P3, P4, P2);

	int Con1 = C1 * C2;
	int Con2 = C3 * C4;

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

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int X1, Y1, X2, Y2;
		cin >> X1 >> Y1 >> X2 >> Y2;

		Root[i] = i;
		Lines[i].first = point(X1, Y1);
		Lines[i].second = point(X2, Y2);
	}

	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (Intersect(Lines[i].first, Lines[i].second, Lines[j].first, Lines[j].second))
			{
				Union(i, j);
			}
		}
	}

	for (int i = 0; i < N; ++i)
	{
		++HashMap[Find(i)];
	}

	int Max = 0;
	for (const pair<int, int>& p : HashMap)
	{
		Max = max(Max, p.second);
	}

	cout << HashMap.size() << '\n';
	cout << Max;
}