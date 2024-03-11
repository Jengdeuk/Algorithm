#include <iostream>
#include <string>
using namespace std;

string Str;
string Bomb;
string Current;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> Str >> Bomb;

	int Length = Bomb.size();
	for (int i = 0; i < Str.size(); ++i)
	{
		Current.push_back(Str[i]);
		int CurSize = Current.size();
		if (CurSize >= Length)
		{
			bool bExplosion = true;
			for (int i = 0; i < Length; ++i)
			{
				if (Current[CurSize - Length + i] != Bomb[i])
				{
					bExplosion = false;
					break;
				}
			}

			if (bExplosion)
			{
				Current.erase(Current.end() - Length, Current.end());
			}
		}
	}

	if (!Current.empty())
	{
		cout << Current;
	}
	else
	{
		cout << "FRULA";
	}
}