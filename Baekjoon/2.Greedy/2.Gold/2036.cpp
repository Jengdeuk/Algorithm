#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int N;
ll S[100000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}

	sort(S, S + N);

	int MidL = lower_bound(S, S + N, 0) - S;
	int MidR = upper_bound(S, S + N, 0) - S;
	int OneL = lower_bound(S, S + N, 1) - S;
	int OneR = upper_bound(S, S + N, 1) - S;

	ll Sum = 0;
	if (OneR - OneL == 0)
	{
		if (MidR - MidL == 0 && MidL == 0)
		{
			// +
			for (int i = N - 1; i >= 0; i -= 2)
			{
				if (i == 0)
				{
					Sum += S[i];
				}
				else
				{
					Sum += S[i] * S[i - 1];
				}
			}
		}
		else if (MidR - MidL == 0)
		{
			// -
			for (int i = 0; i < MidL; i += 2)
			{
				if (i == MidL - 1)
				{
					Sum += S[i];
				}
				else
				{
					Sum += S[i] * S[i + 1];
				}
			}

			// +
			for (int i = N - 1; i >= MidR; i -= 2)
			{
				if (i == MidR)
				{
					Sum += S[i];
				}
				else
				{
					Sum += S[i] * S[i - 1];
				}
			}
		}
		else if (MidL == 0)
		{
			// +
			for (int i = N - 1; i >= MidR; i -= 2)
			{
				if (i == MidR)
				{
					Sum += S[i];
				}
				else
				{
					Sum += S[i] * S[i - 1];
				}
			}
		}
		else
		{
			// -
			for (int i = 0; i < MidL; i += 2)
			{
				if (i == MidL - 1)
				{
					break;
				}
				else
				{
					Sum += S[i] * S[i + 1];
				}
			}

			// +
			for (int i = N - 1; i >= MidR; i -= 2)
			{
				if (i == MidR)
				{
					Sum += S[i];
				}
				else
				{
					Sum += S[i] * S[i - 1];
				}
			}
		}
	}
	else
	{
		if (MidR - MidL == 0 && MidL == 0)
		{
			// +
			for (int i = N - 1; i >= OneR; i -= 2)
			{
				if (i == OneR)
				{
					Sum += S[i];
				}
				else
				{
					Sum += S[i] * S[i - 1];
				}
			}

			Sum += (OneR - OneL);
		}
		else if (MidR - MidL == 0)
		{
			// -
			for (int i = 0; i < MidL; i += 2)
			{
				if (i == MidL - 1)
				{
					Sum += S[i];
				}
				else
				{
					Sum += S[i] * S[i + 1];
				}
			}

			// +
			for (int i = N - 1; i >= OneR; i -= 2)
			{
				if (i == OneR)
				{
					Sum += S[i];
				}
				else
				{
					Sum += S[i] * S[i - 1];
				}
			}

			Sum += (OneR - OneL);
		}
		else if (MidL == 0)
		{
			// +
			for (int i = N - 1; i >= OneR; i -= 2)
			{
				if (i == OneR)
				{
					Sum += S[i];
				}
				else
				{
					Sum += S[i] * S[i - 1];
				}
			}

			Sum += (OneR - OneL);
		}
		else
		{
			// -
			for (int i = 0; i < MidL; i += 2)
			{
				if (i == MidL - 1)
				{
					break;
				}
				else
				{
					Sum += S[i] * S[i + 1];
				}
			}

			// +
			for (int i = N - 1; i >= OneR; i -= 2)
			{
				if (i == OneR)
				{
					Sum += S[i];
				}
				else
				{
					Sum += S[i] * S[i - 1];
				}
			}

			Sum += (OneR - OneL);
		}
	}

	cout << Sum;
}