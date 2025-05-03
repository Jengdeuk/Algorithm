#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	time_t timer = time(NULL);
	struct tm* t = localtime(&timer);

	cout << t->tm_year + 1900 << '\n';
	cout << t->tm_mon + 1 << '\n';
	cout << t->tm_mday;
}