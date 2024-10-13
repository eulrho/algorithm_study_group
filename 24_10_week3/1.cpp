// 알파벳 bj.1987
#include <iostream>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int r, c;
int dy[4] = {0, -1, 0, 1};
int dx[4] = {-1, 0, 1, 0};

int max_cnt;

void move(string *str, bool *arr, int y, int x, int cnt)
{
	int new_y, new_x;
	for (int i=0; i<4; i++) {
		new_y = dy[i] + y;
		new_x = dx[i] + x;
		if (new_y < 0 || new_y >= r || new_x < 0 || new_x >= c)
			continue;
		if (!arr[str[new_y][new_x] - 'A']) {
			arr[str[new_y][new_x] - 'A'] = true;
			move(str, arr, new_y, new_x, cnt + 1);
			arr[str[new_y][new_x] - 'A'] = false;
		}
	}
	max_cnt = max(max_cnt, cnt);
}

int main()
{
	fast;
	cin >> r >> c;

	string str[r];
	bool arr[26] = {false,};
	for (int i=0; i<r; i++) cin >> str[i];
	arr[str[0][0] - 'A'] = true;
	move(str, arr, 0, 0, 1);
	cout << max_cnt;
	return (0);
}