#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> MaxHeap;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int Input;
		cin >> Input;

		if (Input == 0)
		{
			if (MaxHeap.empty())
			{
				cout << 0 << '\n';
			}
			else
			{
				cout << MaxHeap.top() << '\n';
				MaxHeap.pop();
			}
		}
		else
		{
			MaxHeap.emplace(Input);
		}
	}
}