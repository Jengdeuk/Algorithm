#include <iostream>
#include <cmath>
using namespace std;

void Test()
{
	int A, B;
	cin >> A >> B;

	A %= 10;

	int Data = 0;
	switch (A)
	{
	case 0:
		Data = 0;
		break;
	case 1:
		Data = 1;
		break;
	case 2:
		B %= 4;
		switch (B)
		{
		case 0:
			Data = 6;
			break;
		case 1:
			Data = 2;
			break;
		case 2:
			Data = 4;
			break;
		case 3:
			Data = 8;
			break;
		}
		break;
	case 3:
		B %= 4;
		switch (B)
		{
		case 0:
			Data = 1;
			break;
		case 1:
			Data = 3;
			break;
		case 2:
			Data = 9;
			break;
		case 3:
			Data = 7;
			break;
		}
		break;
	case 4:
		B %= 2;
		switch (B)
		{
		case 0:
			Data = 6;
			break;
		case 1:
			Data = 4;
			break;
		}
		break;
	case 5:
		Data = 5;
		break;
	case 6:
		Data = 6;
		break;
	case 7:
		B %= 4;
		switch (B)
		{
		case 0:
			Data = 1;
			break;
		case 1:
			Data = 7;
			break;
		case 2:
			Data = 9;
			break;
		case 3:
			Data = 3;
			break;
		}
		break;
	case 8:
		B %= 4;
		switch (B)
		{
		case 0:
			Data = 6;
			break;
		case 1:
			Data = 8;
			break;
		case 2:
			Data = 4;
			break;
		case 3:
			Data = 2;
			break;
		}
		break;
	case 9:
		B %= 2;
		switch (B)
		{
		case 0:
			Data = 1;
			break;
		case 1:
			Data = 9;
			break;
		}
		break;
	}

	Data %= 10;
	if (Data == 0)
	{
		cout << 10 << '\n';
	}
	else
	{
		cout << Data << '\n';
	}
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