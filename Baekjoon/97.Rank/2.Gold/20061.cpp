#include <iostream>
using namespace std;

const int n = 10;

const int dx[2] = { 1, 0 };
const int dy[2] = { 0, 1 };

const int bx[2] = { -1, 0 };
const int by[2] = { 0, -1 };

bool b[n][n];

int score;

void MoveToBoard(const int t, const int sr, const int sc)
{
	// Blue
	int r = sr;
	int c = sc;
	switch (t)
	{
	case 1:
	case 2:
		while (c < n - 1 && b[r][c + 1] == false)
			c++;
		break;
	case 3:
		while (c < n - 1 && b[r][c + 1] == false && b[r - 1][c + 1] == false)
			c++;
		break;
	}

	b[r][c] = true;
	if (t > 1)
		b[r + by[t - 2]][c + bx[t - 2]] = true;

	// Green
	r = sr;
	c = sc;
	switch (t)
	{
	case 1:
	case 3:
		while (r < n - 1 && b[r + 1][c] == false)
			r++;
		break;
	case 2:
		while (r < n - 1 && b[r + 1][c] == false && b[r + 1][c - 1] == false)
			r++;
		break;
	}

	b[r][c] = true;
	if (t > 1)
		b[r + by[t - 2]][c + bx[t - 2]] = true;
}

void TakeScoreAndMove()
{
	// Blue
	for (int j = n - 1; j >= n - 4; --j)
	{
		bool isTake = true;
		for (int i = 0; i < 4; ++i)
			if (b[i][j] == false)
				isTake = false;

		if (isTake)
		{
			score++;
			for (int k = j - 1; k >= n - 6; --k)
				for (int i = 0; i < 4; ++i)
					b[i][k + 1] = b[i][k];
			j++;
		}
	}

	// Green
	for (int i = n - 1; i >= n - 4; --i)
	{
		bool isTake = true;
		for (int j = 0; j < 4; ++j)
			if (b[i][j] == false)
				isTake = false;

		if (isTake)
		{
			score++;
			for (int k = i - 1; k >= n - 6; --k)
				for (int j = 0; j < 4; ++j)
					b[k + 1][j] = b[k][j];
			i++;
		}
	}
}

void LightMove()
{
	// Blue
	int mcnt = 0;
	for (int j = 2; j >= 1; --j)
	{
		for (int i = 0; i < 4; ++i)
		{
			if (b[i][n - 4 - j])
			{
				mcnt = j;
				j = 0;
				break;
			}
		}
	}

	if (mcnt > 0)
	{
		for (int j = n - 1 - mcnt; j >= n - 4 - mcnt; --j)
			for (int i = 0; i < 4; ++i)
				b[i][j + mcnt] = b[i][j];
	}

	for (int j = n - 6; j <= n - 5; ++j)
		for (int i = 0; i < 4; ++i)
			b[i][j] = false;

	// Green
	mcnt = 0;
	for (int i = 2; i >= 1; --i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (b[n - 4 - i][j])
			{
				mcnt = i;
				i = 0;
				break;
			}
		}
	}

	if (mcnt > 0)
	{
		for (int i = n - 1 - mcnt; i >= n - 4 - mcnt; --i)
			for (int j = 0; j < 4; ++j)
				b[i + mcnt][j] = b[i][j];
	}

	for (int i = n - 6; i <= n - 5; ++i)
		for (int j = 0; j < 4; ++j)
			b[i][j] = false;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int q;
	cin >> q;
	while (q--)
	{
		int t, r, c;
		cin >> t >> r >> c;
		switch (t)
		{
		case 2:
			c++;
			break;
		case 3:
			r++;
			break;
		}

		MoveToBoard(t, r, c);
		TakeScoreAndMove();
		LightMove();
	}

	int cnt = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (b[i][j])
				cnt++;

	cout << score << '\n';
	cout << cnt;
}