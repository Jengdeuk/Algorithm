#include <iostream>
#include <list>
using namespace std;

bool TFriend[51];
int Root[51];
int PartyPrimary[51];

int Find(int Node)
{
	if (Node == Root[Node])
	{
		return Node;
	}

	return Root[Node] = Find(Root[Node]);
}

void Union(int NodeA, int NodeB)
{
	int A = Find(NodeA);
	int B = Find(NodeB);
	
	int NewRoot = min(A, B);
	Root[A] = NewRoot;
	Root[B] = NewRoot;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N, M;
	cin >> N >> M;

	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int Friend;
		cin >> Friend;
		TFriend[Friend] = true;
	}

	for (int i = 1; i <= N; ++i)
	{
		Root[i] = i;
	}

	for (int i = 1; i <= M; ++i)
	{
		int F;
		cin >> F;

		int Primary;
		cin >> Primary;
		PartyPrimary[i] = Primary;

		for (int j = 1; j < F; ++j)
		{
			int Cur;
			cin >> Cur;
			Union(Primary, Cur);
		}
	}

	int Cnt = M;
	for (int i = 1; i <= M; ++i)
	{
		int PartyRoot = Find(PartyPrimary[i]);

		bool bTParty = false;
		for (int j = 1; j <= N; ++j)
		{
			if (TFriend[j] && Find(j) == PartyRoot)
			{
				bTParty = true;
				break;
			}
		}

		if (bTParty)
		{
			--Cnt;
		}
	}

	cout << Cnt;
}