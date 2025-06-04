#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Trie
{
public:
    Trie() : _bFinish(false)
    {
        memset(_Nxt, 0, sizeof(_Nxt));
    }

    ~Trie()
    {
        for (int i = 0; i < 10; i++)
        {
            if (_Nxt[i])
            {
                delete _Nxt[i];
            }
        }
    }

public:
    void Insert(string Str, int Idx)
    {
        if (Str.size() == Idx)
        {
            _bFinish = true;
            return;
        }

        int Cur = Str[Idx] - '0';
        if (_Nxt[Cur] == nullptr)
        {
            _Nxt[Cur] = new Trie();
        }

        _Nxt[Cur]->Insert(Str, Idx + 1);
    }

    Trie* Find(string Str, int Idx)
    {
        if (_bFinish || Str.size() == Idx)
            return this;

        int Cur = Str[Idx] - '0';
        if (_Nxt[Cur] == nullptr)
            return nullptr;

        return _Nxt[Cur]->Find(Str, Idx + 1);
    }

private:
    bool _bFinish;
    Trie* _Nxt[10];
};

void Test()
{
    int N;
    cin >> N;

    Trie Tr;

    bool bWrong = false;
    while (N--)
    {
        string S;
        cin >> S;
        if (bWrong)
        {
            continue;
        }

        if (Tr.Find(S, 0) != nullptr)
        {
            bWrong = true;
            continue;
        }

        Tr.Insert(S, 0);
    }

    if (bWrong == false)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) Test();
}