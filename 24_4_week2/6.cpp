// 치킨 배달 bj.15686
#include <iostream>
#include <cmath>
using namespace std;
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MIN(a, b, c, d) (abs(a - c) + abs(b - d))

typedef struct s_restuarants
{
	int y;
	int x;
	bool is_closed;
} t_restuarants;

typedef struct s_house
{
	int y;
	int x;
} t_house;

int n, m, res_cnt, house_cnt;
int d_min = -1;

int find_d_min(t_restuarants *res, t_house *house)
{
	int sum=0;

	for (int i=0; i<house_cnt; i++) {
		int min = 98, temp;

		for (int j=0; j<res_cnt; j++) {
			if (res[j].is_closed == false) {
				temp = MIN(house[i].y, house[i].x, res[j].y, res[j].x);
				min = min > temp ? temp : min;
			}
		}
		sum += min;
	}
	return (sum);
}

void chicken_restaurants(int cnt, t_restuarants *res, t_house *house, int idx)
{
	if (idx == res_cnt) {
		if (cnt != m) return ;
		int temp = find_d_min(res, house);

		if (d_min == -1) d_min = temp;
		else d_min = d_min > temp ? temp : d_min;
		return ;
	}
	for (int i=idx; i<res_cnt; i++) {
		res[i].is_closed = true;
		chicken_restaurants(cnt - 1, res, house, i + 1);
		res[i].is_closed = false;
		if (res_cnt - (cnt - m) > i)
			chicken_restaurants(cnt, res, house, i + 1);
	}
}

int main()
{
	fast;
	int num;
	t_restuarants res[13];
	t_house house[100];

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			cin >> num;
			if (num == 2) res[res_cnt++] = {i, j, false};
			else if (num == 1) house[house_cnt++] = {i, j};
		}
	}
	chicken_restaurants(res_cnt, res, house, 0);
	cout << d_min;
	return (0);
}
