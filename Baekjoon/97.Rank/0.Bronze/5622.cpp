#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

typedef pair<char, int> Time;

const unordered_map<char, int> Dial =
{
	Time('A', 3), Time('B', 3), Time('C', 3),
	Time('D', 4), Time('E', 4), Time('F', 4),
	Time('G', 5), Time('H', 5), Time('I', 5),
	Time('J', 6), Time('K', 6), Time('L', 6),
	Time('M', 7), Time('N', 7), Time('O', 7),
	Time('P', 8), Time('Q', 8), Time('R', 8), Time('S', 8),
	Time('T', 9), Time('U', 9), Time('V', 9),
	Time('W', 10), Time('X', 10), Time('Y', 10), Time('Z', 10)
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	string Input;
	cin >> Input;

	int Sum = 0;
	for (int i = 0; i < Input.size(); ++i)
	{
		Sum += Dial.find(Input[i])->second;
	}

	cout << Sum;
}