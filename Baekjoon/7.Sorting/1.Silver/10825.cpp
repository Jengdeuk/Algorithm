#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
	string Name;
	int Kor;
	int Eng;
	int Mat;
};

int N;
Student Class[100000];

bool Compare(const Student& L, const Student& R)
{
	return (L.Kor == R.Kor ? (L.Eng == R.Eng ? (L.Mat == R.Mat ? L.Name <= R.Name : L.Mat > R.Mat) : L.Eng < R.Eng) : L.Kor > R.Kor);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> Class[i].Name >> Class[i].Kor >> Class[i].Eng >> Class[i].Mat;
	}

	sort(Class, Class + N, Compare);

	for (int i = 0; i < N; ++i)
	{
		cout << Class[i].Name << '\n';
	}
}