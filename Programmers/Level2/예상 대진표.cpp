#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int answer = 1;

    while (true)
    {
        if (abs(a - b) == 1 && min(a, b) % 2 == 1)
        {
            break;
        }

        a = (a + 1) / 2;
        b = (b + 1) / 2;
        ++answer;
    }

    return answer;
}