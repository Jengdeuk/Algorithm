#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int Number;
	while (cin >> Number && Number != 0)
	{
		string Sequence(to_string(Number));
		string OriginSequence(Sequence);

		reverse(Sequence.begin(), Sequence.end());

		if (Sequence.compare(OriginSequence) == 0)
		{
			cout << "yes\n";
		}
		else
		{
			cout << "no\n";
		}
	}
}