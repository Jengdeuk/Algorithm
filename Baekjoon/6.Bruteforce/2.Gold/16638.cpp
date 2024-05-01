#include <iostream>
#include <string>
#include <climits>
using namespace std;

int N;
string S;
int Max = INT_MIN;

int Cal(char Op, int L, int R)
{
	switch (Op)
	{
	case '+':
		return L + R;
	case '-':
		return L - R;
	case '*':
		return L * R;
	}
}

void DFS(int Cur, int Val)
{
	if (Cur > N)
	{
		Max = max(Max, Val);
		return;
	}

	if (Cur + 2 < N)
	{
		int L = S[Cur] - '0';
		int R = S[Cur + 2] - '0';
		int V = Cal(S[Cur + 1], L, R);

		if (Cur == 0)
		{
			DFS(Cur + 4, V);
		}
		else if (S[Cur + 1] == '*')
		{
			int L = S[Cur] - '0';
			int R = S[Cur + 2] - '0';
			int V = L * R;

			bool bDup = false;
			int Idx = Cur + 3;
			while (Idx < N && S[Idx] == '*')
			{
				bDup = true;
				V *= S[Idx + 1] - '0';
				Idx += 2;
			}

			L = Val;
			R = V;
			V = Cal(S[Cur - 1], L, R);
			DFS((!bDup) ? Cur + 4 : Idx + 1, V);
		}
		else
		{
			L = Val;
			R = V;
			V = Cal(S[Cur - 1], L, R);
			DFS(Cur + 4, V);
		}
	}

	if (Cur == 0)
	{
		DFS(Cur + 2, S[Cur] - '0');
	}
	else if (S[Cur + 1] == '*')
	{
		int L = S[Cur] - '0';
		int R = S[Cur + 2] - '0';
		int V = L * R;
		
		bool bDup = false;
		int Idx = Cur + 3;
		while (Idx < N && S[Idx] == '*')
		{
			bDup = true;
			V *= S[Idx + 1] - '0';
			Idx += 2;
		}

		L = Val;
		R = V;
		V = Cal(S[Cur - 1], L, R);
		DFS((!bDup) ? Cur + 4 : Idx + 1, V);
	}
	else
	{
		int L = Val;
		int R = S[Cur] - '0';
		int V = Cal(S[Cur - 1], L, R);
		DFS(Cur + 2, V);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N >> S;
	DFS(0, 0);
	cout << Max;
}