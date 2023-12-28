// 뱀
#include <iostream>
#include <queue>
#include <utility>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

char board[101][101];
int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};
int body[101][101];
queue<pair<int, int>> q;

int game(int n)
{
	int y = 1, x = 1, l, res=0, current=0;
	int tail_y, tail_x;
	int sec[101];
	char c[101];

	body[1][1] = 1;
	q.push({1, 1});
	cin >> l;
	for (int i=0; i<l; i++)
		cin >> sec[i] >> c[i];
	while (true) {
		y += dy[current];
		x += dx[current];
		if (y < 1 || y > n || x < 1 || x > n) break ;
		if (body[y][x] == 1) break ;
		body[y][x] = 1;
		q.push({y, x});
		if (board[y][x] == 'a')
			board[y][x]  = '0';
		else {
			tail_y = q.front().first;
			tail_x = q.front().second;
			q.pop();
			body[tail_y][tail_x] = 0;
		}
		res++;
		for (int i=0; i<l; i++) {
			if (sec[i] == res) {
				if (c[i] == 'L') {
					current--;
					if (current < 0) current = 3;
				}
				else if (c[i] == 'D') {
					current++;
					if (current > 3) current = 0;
				}
				break ;
			}
		}
	}
	return (res+1);
}

void initial_set(int n)
{
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			board[i][j] = '0';
		}
	}
}

int main()
{
	fast;

	int n, k, y, x;

	cin >> n >> k;
	initial_set(n);
	for (int i=0; i<k; i++) {
		cin >> y >> x;
		board[y][x] = 'a';
	}
	cout << game(n);
	return (0);
}