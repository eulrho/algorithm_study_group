// 감시 bj.15683
#include <iostream>
#include <vector>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
using namespace std;

struct cctv {
	int y;
	int x;
	int type;
	int direction;
};

int min_blind_spot=64;
int board[8][8];
int n, m;

void cctv_1(cctv &c, int copy_board[][8])
{
	if (c.direction == 1) {
		for (int i=c.y - 1; i>=0; i--) {
			if (copy_board[i][c.x] == 6) break ;
			if (copy_board[i][c.x] == 0)
				copy_board[i][c.x] = 7;
		}
	}
	else if (c.direction == 2) {
		for (int i=c.y+1; i<n; i++) {
			if (copy_board[i][c.x] == 6) break ;
			if (copy_board[i][c.x] == 0)
				copy_board[i][c.x] = 7;
		}
	}
	else if (c.direction == 3) {
		for (int i=c.x-1; i>=0; i--) {
			if (copy_board[c.y][i] == 6) break ;
			if (copy_board[c.y][i] == 0)
				copy_board[c.y][i] = 7;
		}
	}
	else {
		for (int i=c.x+1; i<m; i++) {
			if (copy_board[c.y][i] == 6) break ;
			if (copy_board[c.y][i] == 0)
				copy_board[c.y][i] = 7;
		}
	}
}

void cctv_2(cctv &c, int copy_board[][8])
{
	if (c.direction == 1) {
		for (int i=c.x-1; i>=0; i--) {
			if (copy_board[c.y][i] == 6) break ;
			if (copy_board[c.y][i] == 0)
				copy_board[c.y][i] = 7;
		}
		for (int i=c.x+1; i<m; i++) {
			if (copy_board[c.y][i] == 6) break ;
			if (copy_board[c.y][i] == 0)
				copy_board[c.y][i] = 7;
		}
	}
	else {
		for (int i=c.y - 1; i>=0; i--) {
			if (copy_board[i][c.x] == 6) break ;
			if (copy_board[i][c.x] == 0)
				copy_board[i][c.x] = 7;
		}
		for (int i=c.y+1; i<n; i++) {
			if (copy_board[i][c.x] == 6) break ;
			if (copy_board[i][c.x] == 0)
				copy_board[i][c.x] = 7;
		}
	}
}

void cctv_3(cctv &c, int copy_board[][8])
{
	if (c.direction == 1 || c.direction == 4) {
		for (int i=c.y - 1; i>=0; i--) {
			if (copy_board[i][c.x] == 6) break ;
			if (copy_board[i][c.x] == 0)
				copy_board[i][c.x] = 7;
		}
	}
	if (c.direction == 1 || c.direction == 2) {
		for (int i=c.x+1; i<m; i++) {
			if (copy_board[c.y][i] == 6) break ;
			if (copy_board[c.y][i] == 0)
				copy_board[c.y][i] = 7;
		}
	}
	if (c.direction == 2 || c.direction == 3) {
		for (int i=c.y+1; i<n; i++) {
			if (copy_board[i][c.x] == 6) break ;
			if (copy_board[i][c.x] == 0)
				copy_board[i][c.x] = 7;
		}
	}
	if (c.direction == 3 || c.direction == 4){
		for (int i=c.x-1; i>=0; i--) {
			if (copy_board[c.y][i] == 6) break ;
			if (copy_board[c.y][i] == 0)
				copy_board[c.y][i] = 7;
		}
	}
}

void cctv_4(cctv &c, int copy_board[][8])
{
	if (c.direction != 3) {
		for (int i=c.y - 1; i>=0; i--) {
			if (copy_board[i][c.x] == 6) break ;
			if (copy_board[i][c.x] == 0)
				copy_board[i][c.x] = 7;
		}
	}
	if (c.direction != 4) {
		for (int i=c.x+1; i<m; i++) {
			if (copy_board[c.y][i] == 6) break ;
			if (copy_board[c.y][i] == 0)
				copy_board[c.y][i] = 7;
		}
	}
	if (c.direction != 1) {
		for (int i=c.y+1; i<n; i++) {
			if (copy_board[i][c.x] == 6) break ;
			if (copy_board[i][c.x] == 0)
				copy_board[i][c.x] = 7;
		}
	}
	if (c.direction != 2){
		for (int i=c.x-1; i>=0; i--) {
			if (copy_board[c.y][i] == 6) break ;
			if (copy_board[c.y][i] == 0)
				copy_board[c.y][i] = 7;
		}
	}
}

void cctv_5(cctv &c, int copy_board[][8])
{
	for (int i=c.y - 1; i>=0; i--) {
		if (copy_board[i][c.x] == 6) break ;
		if (copy_board[i][c.x] == 0)
			copy_board[i][c.x] = 7;
	}
	for (int i=c.x+1; i<m; i++) {
		if (copy_board[c.y][i] == 6) break ;
		if (copy_board[c.y][i] == 0)
			copy_board[c.y][i] = 7;
	}
	for (int i=c.y+1; i<n; i++) {
		if (copy_board[i][c.x] == 6) break ;
		if (copy_board[i][c.x] == 0)
			copy_board[i][c.x] = 7;
	}
	for (int i=c.x-1; i>=0; i--) {
		if (copy_board[c.y][i] == 6) break ;
		if (copy_board[c.y][i] == 0)
			copy_board[c.y][i] = 7;
	}
}

void check_blind_spot(int copy_board[][8])
{
	int cnt=0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (copy_board[i][j] == 0) cnt++;
		}
	}
	min_blind_spot = min(cnt, min_blind_spot);
}

void find_blind_spot(vector<cctv> &info, int idx)
{
	if (idx == (int)info.size()) {
		int copy_board[8][8];
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++)
				copy_board[i][j] = board[i][j];
		}

		for (int i=0; i<idx; i++) {
			switch (info[i].type) {
				case 1:
					cctv_1(info[i], copy_board);
					break ;
				case 2:
					cctv_2(info[i], copy_board);
					break ;
				case 3:
					cctv_3(info[i], copy_board);
					break ;
				case 4:
					cctv_4(info[i], copy_board);
					break ;
				case 5:
					cctv_5(info[i], copy_board);
					break ;
			}
		}
		check_blind_spot(copy_board);
		return ;
	}

	if (info[idx].type == 1) {
		for (int i=1; i<=4; i++) {
			info[idx].direction = i;
			find_blind_spot(info, idx + 1);
		}
	}
	else if (info[idx].type == 2) {
		for (int i=1; i<=2; i++) {
			info[idx].direction = i;
			find_blind_spot(info, idx + 1);
		}
	}
	else if (info[idx].type == 3) {
		for (int i=1; i<=4; i++) {
			info[idx].direction = i;
			find_blind_spot(info, idx + 1);
		}
	}
	else if (info[idx].type == 4) {
		for (int i=1; i<=4; i++) {
			info[idx].direction = i;
			find_blind_spot(info, idx + 1);
		}
	}
	else find_blind_spot(info, idx + 1);
}

int main()
{
	fast;
	cin >> n >> m;

	vector<cctv> info;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> board[i][j];
			if (board[i][j] != 0 && board[i][j] != 6)
				info.push_back({i, j, board[i][j]});
		}
	}
	find_blind_spot(info, 0);
	cout << min_blind_spot;
	return (0);
}