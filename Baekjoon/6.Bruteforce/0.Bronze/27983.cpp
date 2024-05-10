#include <iostream>
using namespace std;

int X[1000];
int L[1000];
char C[1000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> X[i];
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> L[i];
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> C[i];
	}

	for (int i = 0; i < N - 1; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			if (abs(X[i] - X[j]) <= L[i] + L[j] && C[i] != C[j])
			{
				cout << "YES\n";
				cout << i + 1 << ' ' << j + 1;
				exit(0);
			}
		}
	}

	cout << "NO";
}