// 도영이가 만든 맛있는 음식 bj.2961
#include <iostream>
#include <cmath>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int t_min = 1000000000;

void find_min_diff(int n, int ingredient[][2], int sour, int bitter, int idx)
{
	if (idx >= n) {
		if (!(sour == 1 && bitter == 0))
			t_min = t_min > abs(sour - bitter) ? abs(sour - bitter) : t_min;
		return ;
	}
	for (int i=idx+1; i<=n; i++) {
		find_min_diff(n, ingredient, sour, bitter, i);
		find_min_diff(n, ingredient, sour * ingredient[idx][0], bitter + ingredient[idx][1], i);
	}
}

int main()
{
	fast;
	int n, ingredient[11][2]={0,};

	cin >> n;
	for (int i=0; i<n; i++) cin >> ingredient[i][0] >> ingredient[i][1];
	if (n == 1) {
		cout << abs(ingredient[0][0] - ingredient[0][1]);
		return (0);
	}
	find_min_diff(n, ingredient, 1, 0, 0);
	cout << t_min;
	return (0);
}