// 뱀 bj.3190
#include <iostream>
#include <deque>
#include <map>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

int n, k, l;
int board[101][101] = {0, };

enum Direction {
	UP,
	RIGHT,
	DOWN,
	LEFT
};

int dy[4] = {0, 0, -1, 1};
int dx[4] = {-1, 1, 0, 0};

bool is_end(int y, int x, deque<pair<int, int>> &snake)
{
	if (y == 0 || x == 0 || y == n + 1 || x == n + 1)
		return true;

	for (int i=0; i<(int)snake.size(); i++) {
		if (snake[i].first == y && snake[i].second == x) {
			return true;
		}
	}
	return false;
}

int change_direction(int direction, char info)
{
	if (info == 'L') {
		if (direction == RIGHT) return UP;
		else if (direction == LEFT) return DOWN;
		else if (direction == UP) return LEFT;
		else return RIGHT;
	}
	else {
		if (direction == RIGHT) return DOWN;
		else if (direction == LEFT) return UP;
		else if (direction == UP) return RIGHT;
		else return LEFT;
	}
}

int play_game(map<int, char> &trans)
{
	deque<pair<int, int>> snake;
	int direction = RIGHT, time=0;
	snake.emplace_back(1, 1);

	while (true) {
		time++;
		int y = snake.front().first, x = snake.front().second;

		y += dy[direction];
		x += dx[direction];
		if (is_end(y, x, snake)) break ;

		snake.push_front({y, x});
		if (board[y][x] == 1) board[y][x] = 0;
		else snake.pop_back();

		if (trans.find(time) != trans.end())
			direction = change_direction(direction, trans[time]);
	}
	return time;
}

int main()
{
	fast;
	cin >> n >> k;
	int y, x;
	for (int i=0; i<k; i++) {
		cin >> y >> x;
		board[y][x] = 1;
	}

	cin >> l;
	map<int, char> trans;
	int time; char c;
	for (int i=0; i<l; i++) {
		cin >> time >> c;
		trans[time] = c;
	}

	cout << play_game(trans);
	return (0);
}