#include <iostream>
#include <string>
#include <deque>
using namespace std;

deque<int> Sequence;

void Test()
{
	int N;
	string P, Input;
	cin >> P >> N >> Input;

	int Prev = 1;
	int Next = Input.find(',');
	while (Next != string::npos)
	{
		string Sub = Input.substr(Prev, Next - Prev);
		Sequence.push_back(stoi(Sub));

		Prev = Next + 1;
		Next = Input.find(',', Prev);
	}

	string Sub = Input.substr(Prev, Input.size() - 1);
	if (N != 0)
	{
		Sequence.push_back(stoi(Sub));
	}

	bool Reverse = false;
	for (int i = 0; i < P.size(); ++i)
	{
		switch (P[i])
		{
		case 'R':
			Reverse = !Reverse;
			break;

		case 'D':
			if (Sequence.empty())
			{
				cout << "error\n";
				return;
			}

			if (!Reverse)
			{
				Sequence.pop_front();
			}
			else
			{
				Sequence.pop_back();
			}

			break;
		}
	}

	cout << '[';
	while (!Sequence.empty())
	{
		if (!Reverse)
		{
			cout << Sequence.front();
			Sequence.pop_front();
		}
		else
		{
			cout << Sequence.back();
			Sequence.pop_back();
		}

		if (Sequence.size() != 0)
		{
			cout << ',';
		}
	}
	cout << "]\n";
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