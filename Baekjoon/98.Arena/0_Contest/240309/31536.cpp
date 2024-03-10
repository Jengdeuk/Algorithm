#include <iostream>
#include <climits>
using namespace std;

const int Infinite = INT_MAX;

float MC[5][2];
float KC[5][2];

int MP[5][3];
int KP[5][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	for (int i = 0; i < 5; ++i)
	{
		MP[i][2] = Infinite;
		KP[i][2] = Infinite;
	}

	int MX, MY, A, KX, KY, B, M, K;
	cin >> MX >> MY >> A >> KX >> KY >> B >> M >> K;

	KC[0][0] = KX;
	KC[0][1] = KY;
	KC[1][0] = KX;
	KC[1][1] = KY + B;
	KC[2][0] = KX + B;
	KC[2][1] = KY + B;
	KC[3][0] = KX + B;
	KC[3][1] = KY;
	KC[4][0] = float(KX + KX + B) / 2;
	KC[4][1] = float(KY + KY + B) / 2;
	for (int i = 0; i < M; ++i)
	{
		int X, Y;
		cin >> X >> Y;

		for (int j = 0; j < 5; ++j)
		{
			int Cst = (KC[j][0] - X) * (KC[j][0] - X) + (KC[j][1] - Y) * (KC[j][1] - Y);
			if (Cst < MP[j][2])
			{
				MP[j][0] = X;
				MP[j][1] = Y;
				MP[j][2] = Cst;
			}
		}
	}

	MC[0][0] = MX;
	MC[0][1] = MY;
	MC[1][0] = MX;
	MC[1][1] = MY + A;
	MC[2][0] = MX + A;
	MC[2][1] = MY + A;
	MC[3][0] = MX + A;
	MC[3][1] = MY;
	MC[4][0] = float(MX + MX + A) / 2;
	MC[4][1] = float(MY + MY + A) / 2;
	for (int i = 0; i < K; ++i)
	{
		int X, Y;
		cin >> X >> Y;

		for (int j = 0; j < 5; ++j)
		{
			int Cst = (MC[j][0] - X) * (MC[j][0] - X) + (MC[j][1] - Y) * (MC[j][1] - Y);
			if (Cst < KP[j][2])
			{
				KP[j][0] = X;
				KP[j][1] = Y;
				KP[j][2] = Cst;
			}
		}
	}

	int Min = Infinite;
	int MPX = 0, MPY = 0, KPX = 0, KPY = 0;
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 0; j < 5; ++j)
		{
			int Cst = (MP[i][0] - KP[j][0]) * (MP[i][0] - KP[j][0]) + (MP[i][1] - KP[j][1]) * (MP[i][1] - KP[j][1]);
			if (Cst < Min)
			{
				Min = Cst;
				MPX = MP[i][0];
				MPY = MP[i][1];
				KPX = KP[j][0];
				KPY = KP[j][1];
			}
		}
	}

	cout << Min << '\n';
	cout << MPX << ' ' << MPY << '\n';
	cout << KPX << ' ' << KPY;
}