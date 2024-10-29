// 다오의 데이트 bj.18188
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct path {
	int y, x;
	vector<char> route;

	path(int y, int x) {
		this->y = y;
		this->x = x;
	}
};

int h, w, n;

enum DIRECT {
	A, W, D, S
};

int find_direct(char c)
{
	if (c == 'A') return A;
	else if (c == 'W') return W;
	else if (c == 'D') return D;
	else return S;
}

void move(vector<vector<char> > &direction, string board[], int start_y, int start_x)
{
	int dy[4] = {0, -1, 0, 1};
	int dx[4] = {-1, 0, 1, 0};
	queue<path> q;

	q.push(path(start_y, start_x));

	int y, x;
	vector<char> route;
	for (int i=0; i<n; i++) {
		queue<path> q_tmp;

		while (!q.empty()) {
			y = q.front().y;
			x = q.front().x;
			route = vector<char>(q.front().route);
			q.pop();

			for (int j=0; j<2; j++) {
				int d = find_direct(direction[i][j]);
				if (y + dy[d] < 0 || y + dy[d] >= h || x + dx[d] < 0 || x + dx[d] >= w) continue ;
				if (board[y + dy[d]][x + dx[d]] == '@') continue ;

				path p(y + dy[d], x + dx[d]);
				p.route = vector<char>(route);
				p.route.push_back(direction[i][j]);

				if (board[y + dy[d]][x + dx[d]] == 'Z') {
					cout << "YES\n";

					for (int i=0; i<(int)p.route.size(); i++) {cout << p.route[i];}
					cout << '\n';
					return ;
				}
				q_tmp.push(p);
			}
		}

		q = queue<path>(q_tmp);
	}
	cout << "NO\n";
}

int main()
{
	fast;
	cin >> h >> w;
	int d_y, d_x;
	string board[20];
	for (int i=0; i<h; i++) {
		cin >> board[i];
		for (int j=0; j<w; j++) {
			if (board[i][j] == 'D') {
				d_y = i;
				d_x = j;
			}
		}
	}

	cin >> n;
	vector<vector<char> > direction(n);
	char b, c;
	for (int i=0; i<n; i++) {
		cin >> b >> c;
		direction[i].push_back(b);
		direction[i].push_back(c);
	}

	move(direction, board, d_y, d_x);
	return 0;
}