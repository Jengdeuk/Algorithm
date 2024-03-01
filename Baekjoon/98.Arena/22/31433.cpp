#include <iostream>
#include <string>
using namespace std;

int N;
int Min = 5000000;

const char Character[3] = { 'K', 'S', 'A' };

void Check(string Sub, int Count)
{
	int Index = 0;
	for (int i = 0; i < Sub.size(); ++i)
	{
		if (Sub[i] != Character[Index % 3])
		{
			++Count;
		}
		else
		{
			++Index;
		}
	}
	
	Count += abs(N - Index);
	Min = min(Min, Count);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string X;
	cin >> X;
	N = X.size();

	Check("K" + X, 1);
	Check("KS" + X, 2);
	Check(X, 0);

	cout << Min;
}