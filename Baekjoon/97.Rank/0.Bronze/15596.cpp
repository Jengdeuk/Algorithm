#include <vector>
using namespace std;

long long sum(vector<int>& a)
{
	long long Num = 0;
	for (const int& N : a)
	{
		Num += N;
	}

	return Num;
}