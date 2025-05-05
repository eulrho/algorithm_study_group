// 방문 길이
#include <string>
#include <iostream>
using namespace std;

bool v_board[20][20] = {false};
bool h_board[20][20] = {false};

int solution(string dirs) {
	int answer = 0;
	int pos_y = 0, pos_x = 0;

	for (int i=0; i<(int)dirs.size(); i++) {
		if (dirs[i] == 'U' || dirs[i] == 'D') {
			int start = pos_y, dest;
			if (dirs[i] == 'U') pos_y = min(5, pos_y + 1);
			else pos_y = max(-5, pos_y - 1);

			dest = pos_y;
			if (start != dest && !v_board[pos_x + 5][min(start, dest) + 5]) {
				v_board[pos_x + 5][min(start, dest) + 5] = true;
				answer++;
			}
		}
		else {
			int start = pos_x, dest;
			if (dirs[i] == 'R') pos_x = min(5, pos_x + 1);
			else pos_x = max(-5, pos_x - 1);
			dest = pos_x;

			if (start != dest && !h_board[pos_y + 5][min(start, dest) + 5]) {
				h_board[pos_y + 5][min(start, dest) + 5] = true;
				answer++;
			}
		}
	}
	return answer;
}