#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

typedef vector<int> v;

int S[3];
v V;

void BFS()
{
	queue<v> Q;
	map<v, int> M;

	Q.emplace(v({ 0, 0, S[2] }));
	M[v({ 0, 0, S[2] })] = 1;
	while (!Q.empty())
	{
		int A = Q.front()[0];
		int B = Q.front()[1];
		int C = Q.front()[2];
		Q.pop();

		if (A == 0)
		{
			V.emplace_back(C);
		}

		if (A > 0)
		{
			if (B < S[1])
			{
				int NA = A, NB = B, BB = S[1] - B;
				if (BB >= NA)
				{
					NB += NA;
					NA = 0;
				}
				else
				{
					NB += BB;
					NA -= BB;
				}

				if (M[v({ NA, NB, C })] == 0)
				{
					Q.emplace(v({ NA, NB, C }));
					M[v({ NA, NB, C })] = 1;
				}
			}

			if (C < S[2])
			{
				int NA = A, NC = C, BC = S[2] - C;
				if (BC >= NA)
				{
					NC += NA;
					NA = 0;
				}
				else
				{
					NC += BC;
					NA -= BC;
				}

				if (M[v({ NA, B, NC })] == 0)
				{
					Q.emplace(v({ NA, B, NC }));
					M[v({ NA, B, NC })] = 1;
				}
			}
		}

		if (B > 0)
		{
			if (A < S[0])
			{
				int NA = A, NB = B, BA = S[0] - A;
				if (BA >= NB)
				{
					NA += NB;
					NB = 0;
				}
				else
				{
					NA += BA;
					NB -= BA;
				}

				if (M[v({ NA, NB, C })] == 0)
				{
					Q.emplace(v({ NA, NB, C }));
					M[v({ NA, NB, C })] = 1;
				}
			}

			if (C < S[2])
			{
				int NB = B, NC = C, BC = S[2] - C;
				if (BC >= NB)
				{
					NC += NB;
					NB = 0;
				}
				else
				{
					NC += BC;
					NB -= BC;
				}

				if (M[v({ A, NB, NC })] == 0)
				{
					Q.emplace(v({ A, NB, NC }));
					M[v({ A, NB, NC })] = 1;
				}
			}
		}

		if (C > 0)
		{
			if (A < S[0])
			{
				int NA = A, NC = C, BA = S[0] - A;
				if (BA >= NC)
				{
					NA += NC;
					NC = 0;
				}
				else
				{
					NA += BA;
					NC -= BA;
				}

				if (M[v({ NA, B, NC })] == 0)
				{
					Q.emplace(v({ NA, B, NC }));
					M[v({ NA, B, NC })] = 1;
				}
			}

			if (B < S[1])
			{
				int NB = B, NC = C, BB = S[1] - B;
				if (BB >= NC)
				{
					NB += NC;
					NC = 0;
				}
				else
				{
					NB += BB;
					NC -= BB;
				}

				if (M[v({ A, NB, NC })] == 0)
				{
					Q.emplace(v({ A, NB, NC }));
					M[v({ A, NB, NC })] = 1;
				}
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 3; ++i)
	{
		cin >> S[i];
	}

	BFS();

	sort(V.begin(), V.end());

	for (const int& v : V)
	{
		cout << v << ' ';
	}
}