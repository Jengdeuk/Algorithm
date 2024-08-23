#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    
    int Case = 1;
    while (true)
    {
        int L, P, V;
        cin >> L >> P >> V;
        if (L == 0 && P == 0 && V == 0)
        {
            break;
        }
        
        int Sum = 0;
        while (V > 0)
        {
            int Day = min(V, L);
            Sum += Day;
            V -= P;
        }
        
        cout << "Case " << Case << ": " << Sum << '\n';
        ++Case;
    }
}
