#include <iostream>
using namespace std;

int main()
{
    char s[1001];
    cin.getline(s, 1001);

    int i = 0;
    cin >> i;
    cout << s[i - 1];
}