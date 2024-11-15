#include <iostream>
using namespace std;

int Cow[10];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;

	int Count = 0;
	for (int i = 0; i < N; ++i)
	{
		int A, B;
		cin >> A >> B;
		--A; ++B;
		if (Cow[A] != 0 && Cow[A] != B)
		{
			++Count;
		}

		Cow[A] = B;
	}

	cout << Count;
}