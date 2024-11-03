#include <iostream>

using namespace std;

const int A[5] = { 1, 2, 3, 4, 5 };

int S[5];

bool IsFinished()
{
    for (int i = 0; i < 5; ++i)
    {
        if (S[i] != A[i])
        {
            return false;
        }
    }
    
    return true;
}

int main()
{
    for (int i = 0; i < 5; ++i)
    {
        cin >> S[i];
    }
    
    while (!IsFinished())
    {
        for (int i = 0; i < 4; ++i)
        {
            if (S[i] > S[i + 1])
            {
                int Temp = S[i];
                S[i] = S[i + 1];
                S[i + 1] = Temp;
                
                for (int j = 0; j < 5; ++j)
                {
                    cout << S[j] << ' ';
                }
                cout << '\n';
            }
        }
    }
}
