#include <iostream>
#include <string>
using namespace std;

string Sol[7] =
{
	"Never gonna give you up",
	"Never gonna let you down",
	"Never gonna run around and desert you",
	"Never gonna make you cry",
	"Never gonna say goodbye",
	"Never gonna tell a lie and hurt you",
	"Never gonna stop"
};


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int N;
	cin >> N;
	cin.ignore();

	bool bReplaced = false;
	for (int i = 0; i < N; ++i)
	{
		string S;
		getline(cin, S);

		bool bFound = false;
		for (int j = 0; j < 7; ++j)
		{
			if (S.compare(Sol[j]) == 0)
			{
				bFound = true;
				break;
			}
		}

		if (bFound == false)
		{
			bReplaced = true;
		}
	}

	if (bReplaced)
	{
		cout << "Yes";
	}
	else
	{
		cout << "No";
	}
}