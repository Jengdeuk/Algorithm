#include <iostream>
using namespace std;

int main()
{
	const int size = 8;
	int codes[size] = {};
	for (int i = 0; i < size; ++i)
	{
		cin >> codes[i];
	}

	enum CHECK { ASCENDING, DESCENDING, MIXED, END };
	CHECK state;
	switch (codes[0])
	{
	case 1:
		state = CHECK::ASCENDING;
		for (int i = 0; i < size; ++i)
		{
			if (codes[i] != i + 1)
			{
				state = CHECK::MIXED;
				break;
			}
		}
		break;
	case 8:
		state = CHECK::DESCENDING;
		for (int i = 0; i < size; ++i)
		{
			if (codes[i] != size - i)
			{
				state = CHECK::MIXED;
				break;
			}
		}
		break;
	default:
		state = CHECK::MIXED;
		break;
	}

	switch (state)
	{
	case CHECK::ASCENDING:
		cout << "ascending";
		break;
	case CHECK::DESCENDING:
		cout << "descending";
		break;
	case CHECK::MIXED:
		cout << "mixed";
		break;
	}
}