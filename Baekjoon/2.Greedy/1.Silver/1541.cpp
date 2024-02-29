#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string Input;
	getline(cin, Input);

    // Split Two Set
	int SubtractIndex = Input.find('-');
    string SumString = Input.substr(0, SubtractIndex);
    string SubtractString = (SubtractIndex != string::npos) ? Input.substr(SubtractIndex + 1) : "0";

    // Parsing SumNumbers
    vector<int> SumNumbers;
    SumNumbers.reserve(50);
    int previous = 0;
    int current = min(SumString.find('-'), SumString.find('+'));
    while (current != string::npos) {
        string Buffer = SumString.substr(previous, current - previous);
        SumNumbers.emplace_back(stoi(Buffer));

        previous = current + 1;
        current = min(SumString.find('-', previous), SumString.find('+', previous));
    }
    SumNumbers.emplace_back(stoi(SumString.substr(previous, current - previous)));

    // Parsing SubtractNumbers
    vector<int> SubtractNumbers;
    SubtractNumbers.reserve(50);
    previous = 0;
    current = min(SubtractString.find('-'), SubtractString.find('+'));
    while (current != string::npos) {
        string Buffer = SubtractString.substr(previous, current - previous);
        SubtractNumbers.emplace_back(stoi(Buffer));

        previous = current + 1;
        current = min(SubtractString.find('-', previous), SubtractString.find('+', previous));
    }
    SubtractNumbers.emplace_back(stoi(SubtractString.substr(previous, current - previous)));

    // Solution
    int Result = 0;
    for (const int& Number : SumNumbers)
    {
        Result += Number;
    }
    for (const int& Number : SubtractNumbers)
    {
        Result -= Number;
    }
    cout << Result;
}