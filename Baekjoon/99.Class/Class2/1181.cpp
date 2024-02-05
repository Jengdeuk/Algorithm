#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

template <class _Ty = void>
struct Compare {
	constexpr bool operator()(const _Ty& _Left, const _Ty& _Right) const {
		return (_Left.length() == _Right.length()) ? _Left > _Right : _Left.length() > _Right.length();
	}
};

unordered_set<string> HashTable;
priority_queue<string, vector<string>, Compare<string>> OrderedQueue;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string Word;
		cin >> Word;
		HashTable.emplace(Word);
	}

	for (const string& Word : HashTable)
	{
		OrderedQueue.emplace(Word);
	}

	while (!OrderedQueue.empty())
	{
		cout << OrderedQueue.top() << '\n';
		OrderedQueue.pop();
	}
}