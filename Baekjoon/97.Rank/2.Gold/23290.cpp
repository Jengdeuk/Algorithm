#include <iostream>
#include <list>
#include <cstring>
using namespace std;

typedef pair<int, int > p;
typedef pair<int, p> ip;

const int mSize = 4;

const int mdx[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int mdy[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

const int sdx[4] = { 0, -1, 0, 1 };
const int sdy[4] = { -1, 0, 1, 0 };

int m, sr, sc, smell[mSize][mSize];
list<int> fish[mSize][mSize], summonFish[mSize][mSize];

int maxFish, moveSol[3], moveCur[3], curFish[mSize][mSize];

bool isValidFishMove(int r, int c)
{
	return (r >= 0 && r < mSize && c >= 0 && c < mSize && (r == sr && c == sc) == false && smell[r][c] == 0);
}

bool isValidSharkMove(int r, int c)
{
	return (r >= 0 && r < mSize && c >= 0 && c < mSize);
}

void summonStart()
{
	for (int i = 0; i < mSize; ++i)
		for (int j = 0; j < mSize; ++j)
			summonFish[i][j] = fish[i][j];
}

void moveFish()
{
	list<int> temp[mSize][mSize];
	for (int i = 0; i < mSize; ++i)
	{
		for (int j = 0; j < mSize; ++j)
		{
			for (int d : fish[i][j])
			{
				int od = d;
				int dcnt = 0;
				int nr = i + mdy[d];
				int nc = j + mdx[d];
				while (isValidFishMove(nr, nc) == false && dcnt < 8)
				{
					dcnt++;
					d = (d - 1 < 0) ? 7 : d - 1;
					nr = i + mdy[d];
					nc = j + mdx[d];
				}

				if (dcnt < 8)
					temp[nr][nc].emplace_back(d);
				else
					temp[i][j].emplace_back(od);
			}
		}
	}

	for (int i = 0; i < mSize; ++i)
		for (int j = 0; j < mSize; ++j)
			fish[i][j] = temp[i][j];
}

void bf(int idx, int fishNum, int r, int c)
{
	if (idx == 3)
	{
		if (fishNum > maxFish)
		{
			maxFish = fishNum;
			memcpy(moveSol, moveCur, sizeof(moveSol));
		}

		return;
	}

	for (int i = 0; i < 4; ++i)
	{
		int nr = r + sdy[i];
		int nc = c + sdx[i];
		if (isValidSharkMove(nr, nc))
		{
			moveCur[idx] = i;
			int fn = curFish[nr][nc];
			curFish[nr][nc] = 0;
			bf(idx + 1, fishNum + fn, nr, nc);
			curFish[nr][nc] = fn;
		}
	}
}

void moveShark()
{
	maxFish = 0;
	for (int i = 0; i < mSize; ++i)
		for (int j = 0; j < mSize; ++j)
			curFish[i][j] = fish[i][j].size();

	bf(0, 0, sr, sc);

	if (maxFish == 0)
	{
		int r = sr, c = sc;
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				int nr = r + sdy[j];
				int nc = c + sdx[j];
				if (isValidSharkMove(nr, nc))
				{
					moveSol[i] = j;
					r = nr;
					c = nc;
					break;
				}
			}
		}
	}

	p deletePos[3];
	for (int i = 0; i < 3; ++i)
	{
		int d = moveSol[i];
		int nr = sr + sdy[d];
		int nc = sc + sdx[d];
		if (fish[nr][nc].empty() == false)
			smell[nr][nc] = 3;

		fish[nr][nc].clear();
		deletePos[i] = p(nr, nc);
		sr = nr;
		sc = nc;
	}
}

void blowSmell()
{
	for (int i = 0; i < mSize; ++i)
		for (int j = 0; j < mSize; ++j)
			if (smell[i][j])
				smell[i][j]--;
}

void summonFinish()
{
	for (int i = 0; i < mSize; ++i)
		for (int j = 0; j < mSize; ++j)
			for (const int d : summonFish[i][j])
				fish[i][j].emplace_back(d);
}

void practice()
{
	summonStart();
	moveFish();
	moveShark();
	blowSmell();
	summonFinish();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int s;
	cin >> m >> s;
	while (m--)
	{
		int r, c, d;
		cin >> r >> c >> d;
		r--; c--;
		fish[r][c].emplace_back(d - 1);
	}
	cin >> sr >> sc;
	sr--; sc--;

	while (s--) practice();

	int cnt = 0;
	for (int i = 0; i < mSize; ++i)
		for (int j = 0; j < mSize; ++j)
			cnt += fish[i][j].size();

	cout << cnt;
}