#include <iostream>
using namespace std;

void PrintTree(int N)
{
	for (int i = 0; i < N - 1; ++i)
	{
		cout << ' ';
	}
	cout << "*\n";

	for (int i = 0; i < N - 2; ++i)
	{
		cout << ' ';
	}
	cout << "* *\n";

	for (int i = 0; i < N - 2; ++i)
	{
		cout << ' ';
	}
	cout << "*****\n";

	PrintTree(N - 3);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	PrintTree(N);
}