#include <iostream>
using namespace std;

int Weight[1001][3];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	int R, G, B;
	cin >> R >> G >> B;

	Weight[1][0] = R;
	Weight[1][1] = G;
	Weight[1][2] = B;
	
	for (int i = 2; i <= N; ++i)
	{
		cin >> R >> G >> B;

		Weight[i][0] = min(Weight[i - 1][1], Weight[i - 1][2]) + R;
		Weight[i][1] = min(Weight[i - 1][0], Weight[i - 1][2]) + G;
		Weight[i][2] = min(Weight[i - 1][0], Weight[i - 1][1]) + B;
	}

	cout << min(min(Weight[N][0], Weight[N][1]), Weight[N][2]);
}