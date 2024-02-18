#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<int, int> CheckNum;
priority_queue<int> MaxHeap;
priority_queue<int, vector<int>, greater<int>> MinHeap;

void Input(int Number)
{
	++CheckNum[Number];
	MaxHeap.emplace(Number);
	MinHeap.emplace(Number);
}

void DeleteMax()
{
	if (!MaxHeap.empty())
	{
		int Number = MaxHeap.top();
		MaxHeap.pop();
		--CheckNum[Number];
	}
}

void DeleteMin()
{
	if (!MinHeap.empty())
	{
		int Number = MinHeap.top();
		MinHeap.pop();
		--CheckNum[Number];
	}
}

void CleanHeap()
{
	while (!MaxHeap.empty()
		&& CheckNum[MaxHeap.top()] == 0)
	{
		MaxHeap.pop();
	}

	while (!MinHeap.empty()
		&& CheckNum[MinHeap.top()] == 0)
	{
		MinHeap.pop();
	}
}

void Test()
{
	CheckNum.clear();
	while (!MaxHeap.empty())
	{
		MaxHeap.pop();
	}
	while (!MinHeap.empty())
	{
		MinHeap.pop();
	}

	int K;
	cin >> K;
	for (int i = 0; i < K; ++i)
	{
		char Command;
		int Number;
		cin >> Command >> Number;

		if (Command == 'I')
		{
			Input(Number);
		}
		else if (Command == 'D' && Number == 1)
		{
			DeleteMax();
			CleanHeap();
		}
		else if (Command == 'D' && Number == -1)
		{
			DeleteMin();
			CleanHeap();
		}
	}

	if (MaxHeap.empty() || MinHeap.empty())
	{
		cout << "EMPTY\n";
		return;
	}

	cout << MaxHeap.top() << ' ' << MinHeap.top() << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}