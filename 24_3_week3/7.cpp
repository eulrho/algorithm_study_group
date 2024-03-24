// N-Queen
#include <iostream>
#define fast ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define MIN(a, b) (a < b ? a : b)
using namespace std;

int cnt;

bool check_position(int n, int board[][15], int y, int x)
{
	for (int k=1; k <= MIN(y, x); k++)
		if (board[y-k][x-k] == 1) return (false);
	for (int k=1; k <= MIN(y, n-x-1); k++)
		if (board[y-k][x+k] == 1) return (false);
	for (int k = y - 1; k >= 0; k--)
		if (board[k][x] == 1) return (false);
	for (int k = x - 1; k >= 0; k--)
		if (board[y][k] == 1) return (false);
	return (true);
}

void find_position(int n, int board[][15], int y, int cnt_q)
{
	if (y == n) {
		if (cnt_q == n) cnt++;
		return ;
	}
	for (int i=0; i<n; i++) {
		if (check_position(n, board, y, i) == true) {
			board[y][i] = 1;
			find_position(n, board, y + 1, cnt_q + 1);
			board[y][i] = 0;
		}
	}
}

int main()
{
	fast;
	int n, board[15][15] = {0, };

	cin >> n;
	find_position(n, board, 0, 0);
	cout << cnt;
	return (0);
}