#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	string Pattern;
	cin >> Pattern;

	int Size = Pattern.size();
	for (int i = 1; i < N; ++i)
	{
		string FileName;
		cin >> FileName;

		for (int ch = 0; ch < Size; ++ch)
		{
			if (Pattern[ch] != FileName[ch])
			{
				Pattern[ch] = '?';
			}
		}
	}

	cout << Pattern;
}