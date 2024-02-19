#include <iostream>
#include <string>
using namespace std;

string A, B;

void Add(string A, string B)
{
	int ASize = A.size();
	int BSize = B.size();
	if (ASize > BSize)
	{
		string NewB;
		for (int i = 0; i < ASize - BSize; ++i)
		{
			NewB.push_back('0');
		}
		NewB.append(B);
		B = NewB;
		BSize = ASize;
	}
	else if (ASize < BSize)
	{
		string NewA;
		for (int i = 0; i < BSize - ASize; ++i)
		{
			NewA.push_back('0');
		}
		NewA.append(A);
		A = NewA;
		ASize = BSize;
	}

	string Result;
	for (int i = 0; i < ASize; ++i)
	{
		Result.push_back('0');
	}

	bool bCarry = false;
	for (int i = ASize - 1; i >= 0; --i)
	{
		int Sum = 0;

		if (bCarry)
		{
			bCarry = false;
			Sum = 1;
		}

		int AN = A[i] - '0';
		int BN = B[i] - '0';

		Sum += (AN + BN);
		if (Sum >= 10)
		{
			Sum %= 10;
			bCarry = true;
		}

		Result[i] = Sum + '0';
	}

	string NewResult;
	if (bCarry)
	{
		NewResult.push_back('1');
	}
	NewResult.append(Result);

	bool bZeroCheck = true;
	for (int i = 0; i < NewResult.size(); ++i)
	{
		if (i == NewResult.size() - 1)
		{
			bZeroCheck = false;
		}

		char Current = NewResult[i];
		if (bZeroCheck && Current == '0')
		{
			continue;
		}
		else if (bZeroCheck)
		{
			bZeroCheck = false;
		}

		cout << NewResult[i];
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;

	Add(A, B);
}