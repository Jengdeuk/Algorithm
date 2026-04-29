#include <string>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

const int Inf = INT_MAX;

const int DX[4] = { -1, 0, 1, 0 };
const int DY[4] = { 0, -1, 0, 1 };

vector<vector<int>>* BoardPtr;
int N;
int DP[4][25][25];

struct Node
{
    int CurrCst;
    int PrevDir;
    int R;
    int C;
};

bool IsValid(int R, int C)
{
    return R >= 0 && R < N && C >= 0 && C < N && (*BoardPtr)[R][C] == 0;
}

void BFS()
{
    queue<Node> Q;
    Q.emplace(Node{ 0, -1, 0, 0 });
    while (!Q.empty())
    {
        int CurrCst = Q.front().CurrCst;
        int PrevDir = Q.front().PrevDir;
        int R = Q.front().R;
        int C = Q.front().C;
        Q.pop();

        if (CurrCst > DP[PrevDir][R][C])
        {
            continue;
        }

        for (int i = 0; i < 4; ++i)
        {
            int NR = R + DY[i];
            int NC = C + DX[i];
            if (!IsValid(NR, NC))
            {
                continue;
            }

            int NCst = CurrCst + 100;
            if (PrevDir != -1 && PrevDir != i)
            {
                NCst += 500;
            }

            if (NCst < DP[i][NR][NC])
            {
                DP[i][NR][NC] = NCst;
                Q.emplace(Node{ NCst, i, NR, NC });
            }
        }
    }
}

int solution(vector<vector<int>> board)
{
    BoardPtr = &board;
    N = board.size();

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            DP[0][i][j] = Inf;
            DP[1][i][j] = Inf;
            DP[2][i][j] = Inf;
            DP[3][i][j] = Inf;
        }
    }

    DP[0][0][0] = 0;
    BFS();

    int answer = Inf;
    for (int i = 0; i < 4; ++i)
    {
        answer = min(answer, DP[i][N - 1][N - 1]);
    }

    return answer;
}