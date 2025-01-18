#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int n, m, k;
	cin >> n >> m >> k;
	
	int minimum = min(m, k);
	cout << minimum + (n - minimum - abs(m - k));
}