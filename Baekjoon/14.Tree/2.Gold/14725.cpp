#include <iostream>
#include <string>
#include <map>
using namespace std;

struct Children
{
	~Children()
	{
		for (const auto& Elem : C)
		{
			delete Elem.second;
		}
	}

	map<string, Children*> C;
};

Children* Root;

void Print(Children* Current, int Depth)
{
	for (const auto& Child : Current->C)
	{
		for (int i = 0; i < Depth; ++i)
		{
			cout << "--";
		}
		cout << Child.first << '\n';
		Print(Child.second, Depth + 1);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	Root = new Children;

	int N;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int K;
		cin >> K;

		Children* Current = Root;
		for (int j = 0; j < K; ++j)
		{
			string S;
			cin >> S;

			if (Current->C[S] == nullptr)
			{
				Children* NewChildren = new Children;
				Current->C[S] = NewChildren;
			}

			Current = Current->C[S];
		}
	}

	Print(Root, 0);

	delete Root;
}