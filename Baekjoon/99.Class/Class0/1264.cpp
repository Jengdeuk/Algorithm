#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true)
	{
		string Input;
		getline(cin, Input);

		if (Input.compare("#") == 0)
		{
			break;
		}

		int Count = 0;
		for (int i = 0; i < Input.size(); ++i)
		{
			if (Input[i] == 'a' || Input[i] == 'A'
				|| Input[i] == 'e' || Input[i] == 'E'
				|| Input[i] == 'i' || Input[i] == 'I'
				|| Input[i] == 'o' || Input[i] == 'O'
				|| Input[i] == 'u' || Input[i] == 'U')
			{
				++Count;
			}
		}
		cout << Count << '\n';
	}
}