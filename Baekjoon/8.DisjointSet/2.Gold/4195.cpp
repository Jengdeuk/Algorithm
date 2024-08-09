#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, string> Root;
unordered_map<string, int> Count;

string Find(string Node)
{
	if (Node.compare(Root[Node]) == 0)
	{
		return Node;
	}

	return Root[Node] = Find(Root[Node]);
}

int Union(string NodeA, string NodeB)
{
	string A = Find(NodeA);
	string B = Find(NodeB);
	if (A.compare(B) == 0)
	{
		return Count[A];
	}
	
	string Min = min(A, B);
	Root[A] = Min;
	Root[B] = Min;
	return Count[Min] = Count[A] + Count[B];
}

void Test()
{
	Root.clear();
	Count.clear();

	int F;
	cin >> F;
	for (int i = 0; i < F; ++i)
	{
		string A, B;
		cin >> A >> B;

		if (Root.count(A) == 0)
		{
			Root[A] = A;
			Count[A] = 1;
		}

		if (Root.count(B) == 0)
		{
			Root[B] = B;
			Count[B] = 1;
		}

		cout << Union(A, B) << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		Test();
	}
}