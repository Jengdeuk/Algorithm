#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int N;
string List[5000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string S;
	cin >> S;

	int Size = S.size();
	for (int i = 1; i < Size; ++i)
	{
		for (int j = i + 1; j < Size; ++j)
		{
			string A = S.substr(0, i);
			string B = S.substr(i, j - i);
			string C = S.substr(j, Size - j);
			reverse(A.begin(), A.end());
			reverse(B.begin(), B.end());
			reverse(C.begin(), C.end());
			List[N++].append(A + B + C);
		}
	}

	cout << *min_element(List, List + N);
}