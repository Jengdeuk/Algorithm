#include <string>
#include <vector>

using namespace std;

int GDC(int a, int b)
{
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int LCM(int a, int b)
{
    return a * b / GDC(a, b);
}

int solution(vector<int> arr)
{
    int answer = arr.front();

    int Size = arr.size();
    for (int i = 1; i < Size; ++i)
    {
        answer = LCM(answer, arr[i]);
    }

    return answer;
}