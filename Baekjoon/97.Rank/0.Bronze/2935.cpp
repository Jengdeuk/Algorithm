#include <iostream>
#include <string>
using namespace std;

string A, B;

string Add(string A, string B, bool bMul = false);
void Sub(string A, string B);
void Mul(string A, string B);

string Add(string A, string B, bool bMul)
{
	if (A[0] == '-' && B[0] != '-')
	{
		Sub(B, A.substr(1));
		return string();
	}

	if (A[0] != '-' && B[0] == '-')
	{
		Sub(A, B.substr(1));
		return string();
	}

	bool bMinus = false;
	if (A[0] == '-' && B[0] == '-')
	{
		bMinus = true;
		A = A.substr(1);
		B = B.substr(1);
	}

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

	string Result(ASize, '0');

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
	if (bMinus && bCarry)
	{
		NewResult.append("-1");
	}
	else if (bMinus)
	{
		NewResult.push_back('-');
	}
	else if (bCarry)
	{
		NewResult.push_back('1');
	}
	NewResult.append(Result);

	if (bMul)
	{
		return NewResult;
	}

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

	return string();
}

void Sub(string A, string B)
{
	if (A[0] == '-' && B[0] != '-')
	{
		string NewB = "-";
		Add(A, NewB.append(B));
		return;
	}

	if (A[0] != '-' && B[0] == '-')
	{
		Add(A, B.substr(1));
		return;
	}

	if (A[0] == '-' && B[0] == '-')
	{
		Sub(B.substr(1), A.substr(1));
		return;
	}

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

	bool bMinus = false;
	for (int i = 0; i < ASize; ++i)
	{
		if (A[i] - '0' > B[i] - '0')
		{
			break;
		}
		else if (A[i] - '0' == B[i] - '0')
		{
			continue;
		}
		else if (A[i] - '0' < B[i] - '0')
		{
			string Temp = A;
			A = B;
			B = Temp;
			bMinus = true;
			break;
		}
	}

	string Result(ASize, '0');

	bool bCarry = false;
	for (int i = ASize - 1; i >= 0; --i)
	{
		int Sum = 0;

		if (bCarry)
		{
			bCarry = false;
			Sum = -1;
		}

		int AN = A[i] - '0';
		int BN = B[i] - '0';

		Sum += (AN - BN);
		if (Sum < 0)
		{
			Sum = (10 + Sum);
			bCarry = true;
		}

		Result[i] = Sum + '0';
	}

	string NewResult;
	if (bMinus)
	{
		NewResult.append("-");
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
		if ((bZeroCheck && Current == '0')
			|| (bMinus && Current == '0'))
		{
			continue;
		}
		else if (bZeroCheck)
		{
			bZeroCheck = false;
		}
		else if (bMinus)
		{
			bMinus = false;
		}

		cout << NewResult[i];
	}
	cout << '\n';
}

void Mul(string A, string B)
{
	bool bMinus = false;

	if (A[0] == '-' && B[0] != '-')
	{
		bMinus = true;
		A = A.substr(1);
	}
	else if (A[0] != '-' && B[0] == '-')
	{
		bMinus = true;
		B = B.substr(1);
	}
	else if (A[0] == '-' && B[0] == '-')
	{
		A = A.substr(1);
		B = B.substr(1);
	}

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
	for (int i = ASize - 1; i >= 0; --i)
	{
		string MulString(ASize, '0');

		int Carry = 0;
		for (int j = ASize - 1; j >= 0; --j)
		{
			int Sum = 0;

			if (Carry > 0)
			{
				Sum = Carry;
				Carry = 0;
			}

			int AN = A[j] - '0';
			int BN = B[i] - '0';

			Sum += (AN * BN);
			if (Sum >= 10)
			{
				Carry = Sum / 10;
				Sum %= 10;
			}

			MulString[j] = Sum + '0';
		}

		string UpdateString;
		if (Carry > 0)
		{
			UpdateString.push_back(Carry + '0');
		}

		UpdateString.append(MulString);
		UpdateString += string(ASize - 1 - i, '0');

		Result = Add(Result, UpdateString, true);
	}

	string NewResult;
	if (bMinus)
	{
		NewResult.push_back('-');
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
		if ((bZeroCheck && Current == '0')
			|| (bMinus && Current == '0'))
		{
			continue;
		}
		else if (bZeroCheck)
		{
			bZeroCheck = false;
		}
		else if (bMinus)
		{
			bMinus = false;
		}

		cout << NewResult[i];
	}
	cout << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	char op;
	cin >> A >> op >> B;

	switch (op)
	{
	case '+':
		Add(A, B);
		break;
	case '*':
		Mul(A, B);
		break;
	}
}