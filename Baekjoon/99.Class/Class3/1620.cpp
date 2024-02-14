#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, string> NumToString;
unordered_map<string, string> StringToNum;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; ++i)
	{
		string Pokemon;
		cin >> Pokemon;
		NumToString.emplace(to_string(i), Pokemon);
		StringToNum.emplace(Pokemon, to_string(i));
	}

	for (int i = 0; i < M; ++i)
	{
		string Input;
		cin >> Input;
		if (NumToString.find(Input) != NumToString.end())
		{
			cout << (NumToString.find(Input))->second << '\n';
		}
		else
		{
			cout << (StringToNum.find(Input))->second << '\n';
		}
	}
}