#include <iostream>
#include <queue>
using namespace std;

template <class _Ty>
struct compare {
    constexpr bool operator()(const _Ty& _Left, const _Ty& _Right)
    {
        return (abs(_Left) == abs(_Right)) ? _Left > _Right : abs(_Left) > abs(_Right);
    }
};

priority_queue<int, vector<int>, compare<int>> MinHeap;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        int Input;
        cin >> Input;
        if (Input == 0)
        {
            if (MinHeap.empty())
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << MinHeap.top() << '\n';
                MinHeap.pop();
            }
        }
        else
        {
            MinHeap.emplace(Input);
        }
    }
}