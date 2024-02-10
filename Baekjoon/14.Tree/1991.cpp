#include <iostream>
#include <string>
using namespace std;

string PreorderTree;
string InorderTree;
string PostorderTree;
char Tree[27][2];

void DFS(char Parent)
{
	if (Parent == '.')
	{
		return;
	}

	char LeftChild = Tree[Parent - 65][0];
	char RightChild = Tree[Parent - 65][1];

	PreorderTree.push_back(Parent);
	DFS(LeftChild);
	InorderTree.push_back(Parent);
	DFS(RightChild);
	PostorderTree.push_back(Parent);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		char Parent, Left, Right;
		cin >> Parent >> Left >> Right;

		Tree[Parent - 65][0] = Left;
		Tree[Parent - 65][1] = Right;
	}

	DFS('A');

	cout << PreorderTree << '\n';
	cout << InorderTree << '\n';
	cout << PostorderTree;
}