#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	
	string X;
	for (int i = 0; i < N; ++i)
	{
		string Num;
		cin >> Num;
		X.append(Num);
	}

	string Y;
	for (int i = 0; i < N; ++i)
	{
		string Num;
		cin >> Num;
		Y.append(Num);
	}

	long long XX = stoll(X);
	long long YY = stoll(Y);
	cout << min(XX, YY);
}